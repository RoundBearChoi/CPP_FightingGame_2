#pragma once
#include <vector>
#include "ControllerBase.h"
#include "SpriteEnum.h"
#include "SpriteEnumString.h"

namespace RB::Sprites
{
	class SpriteDataController : public RB::Controllers::ControllerBase
	{
	public:
		SpriteDataController();
		~SpriteDataController() override;
		static inline SpriteDataController* PTR = nullptr;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		const std::string& GetString(SpriteEnum spriteEnum);

	private:
		std::vector<SpriteEnumString*> _vecEnumStrings;
		std::string _empty = "EMPTY";
	};
}