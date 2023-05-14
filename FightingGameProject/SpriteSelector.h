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

	private:
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
	};
}