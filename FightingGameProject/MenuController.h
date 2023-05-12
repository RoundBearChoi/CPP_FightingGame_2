#pragma once
#include "ControllerBase.h"

namespace RB::HBE::Menu
{
	class MenuController : public RB::Controllers::ControllerBase
	{
	public:
		MenuController() = default;
		~MenuController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}