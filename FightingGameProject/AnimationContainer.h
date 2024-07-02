#pragma once
#include <string>

#include "SpriteContainer.h"
#include "AnimationRendererLoader.h"

#include "iAnimationObj.h"

namespace RB::Render
{
	class AnimationContainer
	{
	public:
		AnimationContainer() = default;
		~AnimationContainer();

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
		RB::Sprites::SpriteContainer _spriteContainer;
		AnimationRendererLoader _animationRendererLoader;
		std::vector<iAnimationObj*> _vecCurrentAnimations;
		std::vector<AnimationRenderer*> _vecAnimationRenderers;
	};
}
