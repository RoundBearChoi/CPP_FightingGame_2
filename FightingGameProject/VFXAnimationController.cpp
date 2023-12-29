#include "VFXAnimationController.h"

namespace RB::Render
{
    void VFXAnimationController::Init()
    {
        animationLoader.Init();

        animationLoader.LoadSprite("PNG files/ImpactEffects/hiteffect_0.png", RB::Sprites::SpriteEnum::vfx_hiteffect_0);

        AnimationSpecs hit0Specs;
        hit0Specs.mX_TileCount = 5;
        hit0Specs.mY_TileCount = 1;
        hit0Specs.mTotalSprites = 5;
        hit0Specs.mSkipFixedUpdates = 2;
        hit0Specs.mRenderSize = olc::vf2d{ 73.6f, 76.8f };
        hit0Specs.mRenderOffset = olc::vf2d{ 0.0f, -6.0f };
        hit0Specs.mSpriteEnum = RB::Sprites::SpriteEnum::vfx_hiteffect_0;

        animationLoader.LoadAnimation(hit0Specs, RB::Sprites::SpriteEnum::vfx_hiteffect_0);
    }

    void VFXAnimationController::OnUpdate()
    {
        animationLoader.OnUpdate();
    }

    void VFXAnimationController::OnFixedUpdate()
    {
        animationLoader.OnFixedUpdate();
        
        _DeleteFinishedAnimations();
    }

    void VFXAnimationController::InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos)
    {
        AnimationRenderer* aniRenderer = animationLoader.GetAnimationRenderer(spriteEnum);
        
        //no owner player
        iAnimationObj* animationObj = new AnimationObj(nullptr, aniRenderer, RB::Sprites::PivotType::CENTER);

        animationObj->SetWorldPos(pos);

        animationLoader.AddNewAnimation(animationObj);
    }

    void VFXAnimationController::_DeleteFinishedAnimations()
    {
        auto& vec = animationLoader.GetVecCurrentAnimations();

        std::vector<iAnimationObj*>::const_iterator it = vec.begin();

        while (it != vec.end())
        {
            unsigned int skipFixedUpdates = (*it)->GetAnimationSpecs().mSkipFixedUpdates;
            unsigned int totalSprites = (*it)->GetAnimationSpecs().mTotalSprites;

            unsigned int totalFixedUpdates = (*it)->GetFixedUpdateCount();

            if ((totalSprites - 1) * skipFixedUpdates <= totalFixedUpdates)
            {
                it = animationLoader.DeleteAnimationObj(it);
            }
            else
            {
                ++it;
            }
        }
    }
}