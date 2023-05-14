#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteID.h"

namespace RB::HBE::Menu
{
	class SpriteSelector
	{
	public:
		SpriteSelector() = default;
		~SpriteSelector() = default;

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void SetSelection(int32_t index);

	private:
		void _NextSel();
		void _PrevSel();
		int32_t _LimitSelection(int32_t index);

	private:
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
	};
}