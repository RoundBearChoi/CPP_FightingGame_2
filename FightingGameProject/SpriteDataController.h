#pragma once
#include <vector>

#include "SpriteTypeString.h"

#include "iSpriteDataController.h"

namespace RB::Sprites
{
	class SpriteDataController : public iSpriteDataController
	{
	public:
		SpriteDataController() = default;
		~SpriteDataController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		const std::string& GetString(SpriteType spriteEnum) override;

	private:
		std::vector<SpriteTypeString*> _vecEnumStrings;
		std::string _empty = "EMPTY";
	};
}