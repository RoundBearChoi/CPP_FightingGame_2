#include "VFXAnimationController.h"

namespace RB::Render
{
    VFXAnimationController::VFXAnimationController()
    {
        SetHash(typeid(*this));

        VFX_ANIMATION_CONTROLLER = this;
    }

    VFXAnimationController::~VFXAnimationController()
    {
        VFX_ANIMATION_CONTROLLER = nullptr;
    }

    void VFXAnimationController::Init()
    {
        _ani.Init();

        _ani.LoadSprite("PNG files/ImpactEffects/hiteffect_0.png", RB::Sprites::SpriteEnum::vfx_hiteffect_0);

        AnimationSpecs hit0Specs;
        hit0Specs.mX_TileCount = 5;
        hit0Specs.mY_TileCount = 1;
        hit0Specs.mTotalSprites = 5;
        hit0Specs.mSkipFixedUpdates = 3;
        hit0Specs.mRenderSize = olc::vf2d{ 184.0f, 38.4f };
        hit0Specs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
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
    }

    void VFXAnimationController::InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos)
    {
        AnimationRenderer* aniRenderer = _ani.GetAnimationRenderer(spriteEnum);
        
        //no owner player
        iAnimationObj* animationObj = new AnimationObj(nullptr, aniRenderer);

        animationObj->SetWorldPos(pos);

        _ani.PushCurrentAnimation(animationObj);
    }
}