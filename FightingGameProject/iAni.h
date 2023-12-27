#pragma once
#include <iostream>
#include "PlayerID.h"
#include "iAnimationObj.h"
#include "SpriteEnum.h"
#include "AnimationSpecs.h"
#include "AnimationRenderer.h"

namespace RB::Render
{
	class iAni
	{
	public:
		iAni() = default;
		virtual ~iAni() = default;

		virtual void Init() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void OnUpdate() = 0;

		virtual void LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum) = 0;
		virtual void LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteEnum spriteEnum) = 0; //requires sprite to be loaded first
		virtual void DeleteAnimationObj(RB::Players::PlayerID playerID) = 0;
		virtual void DeleteAnimationObj(unsigned int index) = 0;
		virtual std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it) = 0;
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) = 0;
		virtual iAnimationObj* GetCurrentAnimationObj(unsigned int index) = 0;
		virtual iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteEnum playerSpriteEnum, RB::Sprites::PivotType pivotType) = 0;
		virtual RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID) = 0;
		virtual void AddNewAnimation(iAnimationObj* animationObj) = 0;
		virtual const std::vector<iAnimationObj*>& GetVecCurrentAnimations() = 0;
		virtual AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteEnum spriteEnum) = 0;
	};
}