#pragma once
#include <vector>
#include "ControllerBase.h"
#include "HurtBoxLoader.h"

namespace RB::HurtBox
{
	class HurtBoxDataController : public RB::Controllers::ControllerBase
	{
	public:
		HurtBoxDataController() = default;
		~HurtBoxDataController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		const HurtBoxDataSet& GetDataSet(RB::Sprites::SpriteEnum spriteEnum);

	private:
		HurtBoxLoader _loader;
		std::vector<HurtBoxDataSet> _vecDataSets;
		HurtBoxDataSet _empty{ RB::Sprites::SpriteEnum::NONE };
	};
}