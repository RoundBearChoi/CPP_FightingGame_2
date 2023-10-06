#pragma once
#include "iVFXAnimationController.h"

namespace RB::Render
{
	class VFXAnimationController : public RB::Render::iVFXAnimationController
	{
	public:
		VFXAnimationController();
		~VFXAnimationController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}