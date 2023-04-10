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
		olc::HWButton button = olc::Platform::ptrPGE->GetKey(olc::Key::D);

		if (button.bPressed)
		{
			std::cout << "D pressed.." << std::endl;
		}
	}

	void Idle::OnFixedUpdate()
	{

	}
}