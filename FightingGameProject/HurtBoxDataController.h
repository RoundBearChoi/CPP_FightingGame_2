#pragma once
#include <vector>
#include "ControllerBase.h"
#include "HurtBoxDataLoader.h"

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
		HurtBoxDataSet* GetDataSet(RB::Sprites::SpriteEnum spriteEnum);

	private:
		HurtBoxSpecsLoader _loader;
		std::vector<HurtBoxDataSet> _vecDataSets;
	};
}