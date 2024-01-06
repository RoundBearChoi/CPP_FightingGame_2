#pragma once
#include <string>

#include "SpriteLoader.h"
#include "_AnimationLoader.h"

#include "iAnimationObj.h"

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

		virtual void LoadSprite(std::string path, RB::Sprites::SpriteType spriteEnum);
		virtual void LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteType spriteEnum);
		virtual void DeleteAnimationObjs(RB::Players::PlayerID playerID);
		virtual std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it);
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteEnum);
		virtual iAnimationObj* GetCurrentAnimationObj(unsigned int index);
		virtual iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteType playerSpriteEnum, RB::Sprites::PivotType pivotType);
		virtual RB::Sprites::SpriteType GetSpriteEnum(RB::Players::PlayerID playerID);
		virtual void AddNewAnimation(iAnimationObj* animationObj);
		virtual const std::vector<iAnimationObj*>& GetVecCurrentAnimations();
		virtual AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteEnum);

	protected:
		RB::Sprites::SpriteLoader _spriteLoader;
		_AnimationLoader _aniLoader;
		std::vector<iAnimationObj*> _vecCurrentAnimations;
	};
}