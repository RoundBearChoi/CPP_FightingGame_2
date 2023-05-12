#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "json.h" //temp
#include <cassert>//temp

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

	private:
		void example1();
		void example2();
	};
}