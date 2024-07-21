#pragma once

#include "LoadedPlayerBoxData.h"

#include "../ControllerT.h"
#include "../CharacterType.h"
#include "../SpriteType.h"

namespace RB::Collisions
{
	class iPlayerBoxDataController : public RB::Controllers::ControllerT<iPlayerBoxDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual LoadedPlayerBoxData* GetLoadedData(RB::Players::CharacterType characterType) = 0;
		virtual void AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType) = 0;
	};
}
