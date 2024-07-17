#include "VFXAnimationController.h"

#include "AnimationObj.h"

namespace RB::Render
{
    void VFXAnimationController::Init()
    {
        _animationContainer.Init();

        _animationContainer.LoadSprite("PNG files/ImpactEffects/hiteffect_0.png", RB::Sprites::SpriteType::vfx_hiteffect_0);
        
        _animationContainer.LoadAnimation("AnimationSpecs/vfx_hiteffect_0.aniSpecs");
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

    iAnimationObj* VFXAnimationController::InstantiateAnimation(RB::Sprites::SpriteType spriteType, RB::Vector2 pos)
    {
        AnimationRenderer* aniRenderer = _animationContainer.GetAnimationRenderer(spriteType);
        
        //no owner player
        iAnimationObj* animationObj = new AnimationObj(nullptr, aniRenderer, RB::Sprites::PivotType::CENTER);

        animationObj->SetWorldPos(pos);

        _animationContainer.AddNewAnimation(animationObj);

        return animationObj;
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
