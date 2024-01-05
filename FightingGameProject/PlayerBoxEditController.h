#pragma once

#include "iPlayerBoxEditController.h"

#include "PlayerBox.h"
#include "PlayerID.h"

namespace RB::Collisions
{
	class PlayerBoxEditController : public RB::Collisions::iPlayerBoxEditController
	{
	public:
		PlayerBoxEditController() = default;
		~PlayerBoxEditController() override {}

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		PlayerBox* _GetPlayerBox(RB::Players::PlayerID id);
	};
}