#pragma once
#include "ControllerBase.h"

namespace RB::HurtBox
{
	class HurtBoxEditController : public RB::Controllers::ControllerBase
	{
	public:
		HurtBoxEditController() = default;
		~HurtBoxEditController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}