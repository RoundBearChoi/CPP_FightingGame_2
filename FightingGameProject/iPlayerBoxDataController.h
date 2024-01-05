#pragma once

#include "ControllerT.h"

#include "LoadedPlayerBoxData.h"
#include "CharacterType.h"
#include "PlayerBoxSpecs.h"

namespace RB::Collisions
{
	class iPlayerBoxDataController : public RB::Controllers::ControllerT<iPlayerBoxDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual LoadedPlayerBoxData* GetLoadedData(RB::Players::CharacterType characterType) = 0;
		virtual PlayerBoxSpecs* AddSpecs(RB::Collisions::PlayerBoxSpecs specs) = 0;
	};
}