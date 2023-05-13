#pragma once
#include "ControllerBase.h"
#include "HurtBoxDataLoader.h"

namespace RB::HurtBox
{
	class HurtBoxDataController : public RB::Controllers::ControllerBase
	{
	public:
		HurtBoxDataController() = default;
		~HurtBoxDataController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		HurtBoxDataLoader _loader;

	private:
		std::vector<HurtBoxData*> _vecData;
	};
}