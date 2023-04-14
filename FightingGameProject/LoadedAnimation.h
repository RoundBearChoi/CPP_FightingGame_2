#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"
#include "PivotType.h"
#include "LoadedSprite.h"
#include "CurrentCam.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class LoadedAnimation
	{
	public:
		LoadedAnimation(AnimationSpecs specs);
		~LoadedAnimation();

	public:
		AnimationSpecs GetAnimationSpecs();
		//RB::Sprites::SpriteID GetSpriteID();
		//unsigned int GetXTileCount();
		//unsigned int GetYTileCount();
		//unsigned int GetTotalSprites();

	public:
		void RenderAnimation(AnimationRenderSettings animationRenderSettings);
		//unsigned int GetFixedUpdateSkipCount();
		//olc::vi2d GetSpriteSize();

	private:
		AnimationSpecs _animationSpecs;
		//unsigned int _xTileCount;
		//unsigned int _yTileCount;
		//unsigned int _totalSprites;
		//unsigned int _skipFixedUpdates;
		//RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
		//RB::Sprites::LoadedSprite* _loadedSprite = nullptr;
	};
}