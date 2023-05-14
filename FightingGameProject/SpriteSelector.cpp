#include "SpriteSelector.h"

namespace RB::HBE::Menu
{
	void SpriteSelector::Init()
	{
		SetSelection(0);
	}

	void SpriteSelector::OnUpdate()
	{
		_NextSel();
		_PrevSel();
	}

	void SpriteSelector::OnFixedUpdate()
	{

	}

	void SpriteSelector::SetSelection(int32_t index)
	{
		_spriteID = static_cast<RB::Sprites::SpriteID>(index);

		std::cout << "SpriteID: " << index << std::endl;
	}

	void SpriteSelector::_NextSel()
	{
		olc::HWButton homeButton = olc::Platform::ptrPGE->GetKey(olc::Key::HOME);

		if (homeButton.bPressed)
		{
			int32_t current = static_cast<int32_t>(_spriteID);
			current++;
			current = _LimitSelection(current);
			SetSelection(current);
		}
	}

	void SpriteSelector::_PrevSel()
	{
		olc::HWButton endButton = olc::Platform::ptrPGE->GetKey(olc::Key::END);

		if (endButton.bPressed)
		{
			int32_t current = static_cast<int32_t>(_spriteID);
			current--;
			current = _LimitSelection(current);
			SetSelection(current);
		}
	}

	int32_t SpriteSelector::_LimitSelection(int32_t index)
	{
		if (index < 0)
		{
			index = static_cast<int32_t>(RB::Sprites::SpriteID::COUNT) - 1;
		}
		else if (index >= static_cast<int32_t>(RB::Sprites::SpriteID::COUNT))
		{
			index = 0;
		}

		return index;
	}
}