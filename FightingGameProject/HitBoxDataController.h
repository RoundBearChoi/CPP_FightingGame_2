#pragma once

#include "HB.h"

#include "iHitBoxDataController.h"

namespace RB::HBox
{
	class HitBoxDataController : public iHitBoxDataController
	{
	public:
		HitBoxDataController(std::string dir);
		~HitBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		HBoxDataList* GetDataList(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const override;

	private:
		HB _hb;
	};
}