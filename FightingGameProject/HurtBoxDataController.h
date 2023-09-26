#pragma once

#include "HB.h"

#include "iHurtBoxDataController.h"

namespace RB::HBox
{
	class HurtBoxDataController : public iHurtBoxDataController
	{
	public:
		HurtBoxDataController(std::string dir);
		~HurtBoxDataController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		HBoxDataList* GetDataList(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const override;

	private:
		HB _hb;
	};
}