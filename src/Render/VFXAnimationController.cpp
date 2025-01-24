#include "VFXAnimationController.h"

namespace RB::Render
{
    void VFXAnimationController::Init()
    {
        INIT_CONTROLLER
        
        _animationContainer.Init();

        _animationContainer.LoadSprite("../resource/PNG files/ImpactEffects/vfx_hiteffect_0.png", RB::Sprites::SpriteType::vfx_hiteffect_0);
        _animationContainer.LoadSprite("../resource/PNG files/ImpactEffects/vfx_hiteffect_head.png", RB::Sprites::SpriteType::vfx_hiteffect_head);
        _animationContainer.LoadSprite("../resource/PNG files/ImpactEffects/vfx_hiteffect_body.png", RB::Sprites::SpriteType::vfx_hiteffect_body);
        _animationContainer.LoadSprite("../resource/PNG files/ImpactEffects/vfx_hiteffect_leg.png", RB::Sprites::SpriteType::vfx_hiteffect_leg);

        _animationContainer.LoadAnimation("../resource/AnimationSpecs/vfx_hiteffect_0.aniSpecs");
        _animationContainer.LoadAnimation("../resource/AnimationSpecs/vfx_hiteffect_head.aniSpecs");
        _animationContainer.LoadAnimation("../resource/AnimationSpecs/vfx_hiteffect_body.aniSpecs");
        _animationContainer.LoadAnimation("../resource/AnimationSpecs/vfx_hiteffect_leg.aniSpecs");
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

    iAnimationObj* VFXAnimationController::InstantiateAnimation(RB::Sprites::SpriteType spriteType, RB::Vector2 pos, bool faceRight)
    {
        AnimationRenderer* aniRenderer = _animationContainer.GetAnimationRenderer(spriteType);
        
        //no owner player
        iAnimationObj* animationObj = new AnimationObj(nullptr, aniRenderer, RB::Sprites::PivotType::CENTER);
        
        animationObj->FaceRight(faceRight);

        animationObj->SetWorldPos(pos);

        _animationContainer.AddNewAnimation(animationObj);

        if (animationObj != nullptr)
        {
            //std::cout << std::endl;
            //std::cout << "instantiating animation.. sprite type: " << spriteType._to_string() << std::endl;
        }

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

            if (totalSprites * skipFixedUpdates <= totalFixedUpdates)
            {
                //std::cout << std::endl;
                //std::cout << "deleting vfx.. " << (*it)->GetAnimationSpecs().mSpriteType._to_string() <<  std::endl;
                //std::cout << "fixed update count: " << totalFixedUpdates << std::endl;

                it = _animationContainer.DeleteAnimationObj(it);
            }
            else
            {
                ++it;
            }
        }
    }
}
