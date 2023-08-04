#pragma once
#include <vector>
#include "HBoxLoader.h"

#include "iHurtBoxDataController.h"

namespace RB::HBox
{
	class HurtBoxDataController : public iHurtBoxDataController
	{
	public:
		HurtBoxDataController();
		~HurtBoxDataController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		HBoxDataset* GetDataset(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) override;

	private:
		HBoxLoader _loader;
		std::vector<HBoxDataset> _vecDataSets;

	private:
		std::string _none = "none";
		std::string _testing = "testing";
	};
}