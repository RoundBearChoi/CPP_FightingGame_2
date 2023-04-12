#include "FallDown.h"

namespace RB::PlayerStates
{
	FallDown::FallDown()
	{

	}

	FallDown::~FallDown()
	{

	}

	void FallDown::OnEnter()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		RB::Players::PlayerID id = owner->GetPlayerID();

		std::cout << std::endl;
		std::cout << "player " << static_cast<int>(id) << " fall down" << std::endl;
	}

	void FallDown::OnUpdate()
	{

	}

	void FallDown::OnFixedUpdate()
	{

	}
}