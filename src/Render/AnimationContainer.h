#pragma once

#include <string>

#include "AnimationObj.h"
#include "AnimationRenderer.h"

#include "iAnimationObj.h"

#include "../JParser.h"
#include "../Sprites/SpriteContainer.h"

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

	public:
		AnimationSpecs LoadAnimationSpecsFromJSON(std::string path);
		Sprites::LoadedSprite* LoadSprite(std::string path, Sprites::SpriteType spriteType);
		AnimationRenderer* LoadAnimation(std::string specsPath);
		void DeleteAnimationObjs(Players::PLAYER_TYPE playerID);
		std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it);
		iAnimationObj* GetCurrentAnimationObj(Players::PLAYER_TYPE playerID, Sprites::SpriteType spriteType);
		iAnimationObj* GetCurrentAnimationObj(unsigned int index);
		iAnimationObj* InstantiateNewAnimationObj(Players::iPlayer& player, Sprites::SpriteType spriteType, Sprites::PivotType pivotType);
		Sprites::SpriteType GetSpriteType(Players::PLAYER_TYPE playerID);
		void AddNewAnimation(iAnimationObj* animationObj);
		const std::vector<iAnimationObj*>& GetVecCurrentAnimations();
		AnimationRenderer* GetAnimationRenderer(Sprites::SpriteType spriteType);

	protected:
		std::vector<iAnimationObj*> _vecCurrentAnimations; // current running animations
		Sprites::SpriteContainer _spriteContainer;
		std::vector<AnimationRenderer*> _vecAnimationRenderers; // all loaded animations
	};
}
