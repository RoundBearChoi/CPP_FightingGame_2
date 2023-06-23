#pragma once
#include <vector>
#include "ControllerBase.h"
#include "HBoxLoader.h"

namespace RB::HBox
{
	class HurtBoxDataController : public RB::Controllers::ControllerBase
	{
	public:
		HurtBoxDataController();
		~HurtBoxDataController() override;
		static inline HurtBoxDataController* PTR = nullptr;

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
		std::string _testing = "testing";
	};
}