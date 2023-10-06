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

    }

    void VFXAnimationController::OnUpdate()
    {

    }

    void VFXAnimationController::OnFixedUpdate()
    {

    }
}