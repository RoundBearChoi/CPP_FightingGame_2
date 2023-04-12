#include "JumpUp.h"

namespace RB::PlayerStates
{
	JumpUp::JumpUp()
	{

	}

	JumpUp::~JumpUp()
	{

	}

	void JumpUp::OnEnter()
	{
		RB::Players::PlayerID id = GetOwnerPlayer()->GetPlayerID();

		std::cout << "player " << static_cast<int>(id) << " jump up" << std::endl;
	}

	void JumpUp::OnUpdate()
	{

	}

	void JumpUp::OnFixedUpdate()
	{

	}
}