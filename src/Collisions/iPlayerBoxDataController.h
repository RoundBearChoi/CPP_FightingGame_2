#pragma once

#include "LoadedPlayerBoxData.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/CharacterType.h"
#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	#define GET_PLAYER_BOX_DATA_CONTROLLER static_cast<Collisions::iPlayerBoxDataController*>(Controllers::GetController(Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER))

	class iPlayerBoxDataController : public Controllers::ControllerBase
	{
	public:
		virtual LoadedPlayerBoxData* GetLoadedData(Players::CharacterType characterType) = 0;
		virtual void AddSpecs(PlayerBox box, Sprites::SpriteType spriteType, Players::CharacterType characterType) = 0;
	};
}