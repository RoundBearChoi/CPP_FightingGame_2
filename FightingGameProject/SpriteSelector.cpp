#include "SpriteSelector.h"

namespace RB::HBE::Menu
{
	void SpriteSelector::Init()
	{

	}

	void SpriteSelector::OnUpdate()
	{
		olc::HWButton homeButton = olc::Platform::ptrPGE->GetKey(olc::Key::HOME);
		olc::HWButton endButton = olc::Platform::ptrPGE->GetKey(olc::Key::END);

		if (homeButton.bPressed)
		{
			int32_t current = static_cast<int32_t>(_spriteID);
			current++;

			return;
		}

		if (endButton.bPressed)
		{

			int32_t current = static_cast<int32_t>(_spriteID);
			current--;

			return;
		}
	}

	void SpriteSelector::OnFixedUpdate()
	{

	}
}