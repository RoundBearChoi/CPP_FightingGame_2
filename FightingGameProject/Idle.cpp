#include "Idle.h"

namespace RB::PlayerStates
{
	Idle::Idle()
	{

	}

	Idle::~Idle()
	{
		//std::cout << "destroying Idle" << std::endl;
	}

	void Idle::OnEnter()
	{

	}

	void Idle::OnUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();

		//olc::HWButton button = olc::Platform::ptrPGE->GetKey(olc::Key::D);
		//
		//if (button.bPressed)
		//{
		//	std::cout << "D pressed.." << std::endl;
		//}

		olc::HWButton button = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (button.bPressed)
		{
			std::cout << "D pressed.." << " player: " << static_cast<int>(owner->GetPlayerID()) << std::endl;
		}
	}

	void Idle::OnFixedUpdate()
	{

	}
}