#include "VFXAnimationController.h"

namespace RB::Render
{
    void VFXAnimationController::Init()
    {
        _ani.Init();

        _ani.LoadSprite("PNG files/ImpactEffects/hiteffect_0.png", RB::Sprites::SpriteEnum::vfx_hiteffect_0);

        AnimationSpecs hit0Specs;
        hit0Specs.mX_TileCount = 5;
        hit0Specs.mY_TileCount = 1;
        hit0Specs.mTotalSprites = 5;
        hit0Specs.mSkipFixedUpdates = 2;
        hit0Specs.mRenderSize = olc::vf2d{ 73.6f, 76.8f };
        hit0Specs.mRenderOffset = olc::vf2d{ 0.0f, -6.0f };
        hit0Specs.mSpriteEnum = RB::Sprites::SpriteEnum::vfx_hiteffect_0;

        _ani.LoadAnimation(hit0Specs, RB::Sprites::SpriteEnum::vfx_hiteffect_0);
    }

    void VFXAnimationController::OnUpdate()
    {
        _ani.OnUpdate();
    }

    void VFXAnimationController::OnFixedUpdate()
    {
        _ani.OnFixedUpdate();
        
        _DeleteUsedAnimations();
    }

    void VFXAnimationController::InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos)
    {
        AnimationRenderer* aniRenderer = _ani.GetAnimationRenderer(spriteEnum);
        
        //no owner player
        iAnimationObj* animationObj = new AnimationObj(nullptr, aniRenderer, RB::Sprites::PivotType::CENTER);

        animationObj->SetWorldPos(pos);

        _ani.PushCurrentAnimation(animationObj);
    }

    void VFXAnimationController::_DeleteUsedAnimations()
    {
        int count = _ani.GetCurrentAniCount();

        for (int i = count - 1; i >= 0; i--)
        {
            iAnimationObj* aniObj = _ani.GetCurrentAnimationObj(i);

            int skipFixedUpdates = aniObj->GetAnimationSpecs().mSkipFixedUpdates;
            int totalSprites = aniObj->GetAnimationSpecs().mTotalSprites;

            unsigned int totalFixedUpdates = aniObj->GetFixedUpdateCount();

            if ((totalSprites - 1) * skipFixedUpdates <= totalFixedUpdates)
            {
                _ani.DeleteAnimationObj(i);
			}
        }
    }
}