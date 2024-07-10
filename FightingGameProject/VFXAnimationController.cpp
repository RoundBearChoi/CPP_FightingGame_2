#include "VFXAnimationController.h"

#include "AnimationObj.h"

namespace RB::Render
{
    void VFXAnimationController::Init()
    {
        _animationContainer.Init();

        _animationContainer.LoadSprite("PNG files/ImpactEffects/hiteffect_0.png", RB::Sprites::SpriteType::vfx_hiteffect_0);

        AnimationSpecs hit0Specs;
        hit0Specs.mX_TileCount = 5;
        hit0Specs.mY_TileCount = 1;
        hit0Specs.mTotalSprites = 5;
        hit0Specs.mSkipFixedUpdates = 2;
        hit0Specs.mRenderOffset = olc::vf2d{ 0.0f, -6.0f };
        hit0Specs.mRenderScale = 0.15f;
        hit0Specs.mSpriteType = RB::Sprites::SpriteType::vfx_hiteffect_0;

        _animationContainer.LoadAnimation(hit0Specs);
    }

    void VFXAnimationController::OnUpdate()
    {
        _animationContainer.OnUpdate();
    }

    void VFXAnimationController::OnFixedUpdate()
    {
        _animationContainer.OnFixedUpdate();
        
        _DeleteFinishedAnimations();
    }

    void VFXAnimationController::InstantiateAnimation(RB::Sprites::SpriteType spriteType, olc::vf2d pos)
    {
        AnimationRenderer* aniRenderer = _animationContainer.GetAnimationRenderer(spriteType);
        
        //no owner player
        iAnimationObj* animationObj = new AnimationObj(nullptr, aniRenderer, RB::Sprites::PivotType::CENTER);

        animationObj->SetWorldPos(pos);

        _animationContainer.AddNewAnimation(animationObj);
    }

    void VFXAnimationController::_DeleteFinishedAnimations()
    {
        auto& vec = _animationContainer.GetVecCurrentAnimations();

        std::vector<iAnimationObj*>::const_iterator it = vec.begin();

        while (it != vec.end())
        {
            unsigned int skipFixedUpdates = (*it)->GetAnimationSpecs().mSkipFixedUpdates;
            unsigned int totalSprites = (*it)->GetAnimationSpecs().mTotalSprites;

            unsigned int totalFixedUpdates = (*it)->GetFixedUpdateCount();

            if ((totalSprites - 1) * skipFixedUpdates <= totalFixedUpdates)
            {
                it = _animationContainer.DeleteAnimationObj(it);
            }
            else
            {
                ++it;
            }
        }
    }
}