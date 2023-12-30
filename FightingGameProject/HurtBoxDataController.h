#pragma once

#include <string>

#include "iHurtBoxDataController.h"
#include "Loaded_HB_Data.h"
#include "HB_Loader.h"
#include "SpriteEnum.h"


namespace RB::HBox
{
	class HurtBoxDataController : public iHurtBoxDataController
	{
	public:
		HurtBoxDataController(std::string dir);
		~HurtBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		Loaded_HB_Data* GetData(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const override;

	private:
		HB_Loader _hbLoader;
	};
}