#pragma once
#include "iAnimationObj.h"
#include "AnimationObj.h"

#include "Sprites.h"
#include "_AnimationLoader.h"

namespace RB::Render
{
	class AnimationLoader
	{
	public:
		AnimationLoader() = default;
		~AnimationLoader();

		virtual void Init();
		virtual void OnFixedUpdate();
		virtual void OnUpdate();

		virtual void LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum);
		virtual void LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteEnum spriteEnum);
		virtual void DeleteAnimationObjs(RB::Players::PlayerID playerID);
		virtual std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it);
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum);
		virtual iAnimationObj* GetCurrentAnimationObj(unsigned int index);
		virtual iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteEnum playerSpriteEnum, RB::Sprites::PivotType pivotType);
		virtual RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID);
		virtual void AddNewAnimation(iAnimationObj* animationObj);
		virtual const std::vector<iAnimationObj*>& GetVecCurrentAnimations();
		virtual AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteEnum spriteEnum);

	protected:
		RB::Sprites::SpriteLoader _sprites;
		_AnimationLoader _aniLoader;
		std::vector<iAnimationObj*> _vecCurrentAnimations;
	};
}