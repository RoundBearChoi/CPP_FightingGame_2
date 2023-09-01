#pragma once

#include "HB.h"

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

		HBoxDataList* GetDataList(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) override;

	private:
		HB _hb;
	};
}