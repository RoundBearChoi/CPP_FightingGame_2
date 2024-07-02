#pragma once
#include <string>

#include "SpriteContainer.h"
#include "AnimationRenderer.h"

#include "iAnimationObj.h"

namespace RB::Render
{
	class AnimationContainer
	{
	public:
		AnimationContainer() = default;
		~AnimationContainer();

		void Init();
		void OnFixedUpdate();
		void OnUpdate();

		bool LoadSprite(std::string path, RB::Sprites::SpriteType spriteType);
		void LoadAnimation(AnimationSpecs specs);
		void DeleteAnimationObjs(RB::Players::PlayerID playerID);
		std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it);
		iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType);
		iAnimationObj* GetCurrentAnimationObj(unsigned int index);
		iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteType spriteType, RB::Sprites::PivotType pivotType);
		RB::Sprites::SpriteType GetSpriteType(RB::Players::PlayerID playerID);
		void AddNewAnimation(iAnimationObj* animationObj);
		const std::vector<iAnimationObj*>& GetVecCurrentAnimations();
		AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteType);

	protected:
		RB::Sprites::SpriteContainer _spriteContainer;
		std::vector<iAnimationObj*> _vecCurrentAnimations;
		std::vector<AnimationRenderer*> _vecAnimationRenderers;
	};
}
