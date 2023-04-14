#include "TestComponent.h"

namespace RB::States
{
	void TestComponent::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = _state->GetOwnerPlayer();

		player->Move(olc::vi2d{ 1, 0 });
	}
}