#pragma once
#include <vector>
#include "ControllerBase.h"
#include "HBoxLoader.h"

namespace RB::HBox
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
		HBoxDataSet* GetDataSet(RB::Sprites::SpriteEnum spriteEnum);
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum);

	private:
		HBoxLoader _loader;
		std::vector<HBoxDataSet> _vecDataSets;

	private:
		std::string _none = "none";
	};
}