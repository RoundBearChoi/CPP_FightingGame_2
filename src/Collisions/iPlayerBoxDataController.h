#pragma once

#include "LoadedPlayerBoxData.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/CharacterType.h"
#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	#define GET_PLAYER_BOX_DATA_CONTROLLER static_cast<RB::Collisions::iPlayerBoxDataController*>(RB::Controllers::GetController(Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER))

	class iPlayerBoxDataController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual LoadedPlayerBoxData* GetLoadedData(RB::Players::CharacterType characterType) = 0;
		virtual void AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType) = 0;
	};
}