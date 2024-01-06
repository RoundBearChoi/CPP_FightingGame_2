#pragma once

#include <string>

#include "iHitBoxDataController.h"
#include "Loaded_HB_Data.h"
#include "HB_Loader.h"

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

		Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteType spriteEnum) const override;

	private:
		HB_Loader _hbLoader;
	};
}