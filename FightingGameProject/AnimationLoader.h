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

		virtual bool LoadSprite(std::string path, RB::Sprites::SpriteType spriteType);
		virtual void LoadAnimation(AnimationSpecs specs);
		virtual void DeleteAnimationObjs(RB::Players::PlayerID playerID);
		virtual std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it);
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType);
		virtual iAnimationObj* GetCurrentAnimationObj(unsigned int index);
		virtual iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteType spriteType, RB::Sprites::PivotType pivotType);
		virtual RB::Sprites::SpriteType GetSpriteType(RB::Players::PlayerID playerID);
		virtual void AddNewAnimation(iAnimationObj* animationObj);
		virtual const std::vector<iAnimationObj*>& GetVecCurrentAnimations();
		virtual AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteType);

	protected:
		RB::Sprites::SpriteLoader _spriteLoader;
		_AnimationLoader _aniLoader;
		std::vector<iAnimationObj*> _vecCurrentAnimations;
	};
}
