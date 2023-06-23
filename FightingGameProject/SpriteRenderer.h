#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteLoader.h"
#include "SpriteEnum.h"
#include "LoadedSprite.h"
#include "PivotType.h"

#include "CamController.h"

namespace RB::Render
{
	class SpriteRenderer
	{
	public:
		SpriteRenderer() = default;
		~SpriteRenderer() = default;

	public:
		void Init();

	public:
		void LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum);
		void RenderSprite(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType);
		RB::Sprites::LoadedSprite* GetLoadedSprite(RB::Sprites::SpriteEnum spriteEnum);

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}