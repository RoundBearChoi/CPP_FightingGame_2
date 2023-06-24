#pragma once
#include "SpriteRenderer.h"
#include "AABB.h"

#include "ActivePlayerStates.h"

#include "HurtBoxDataController.h"

#include "iPlayerAnimationController.h"
#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerHurtBoxRenderer
	{
	public:
		PlayerHurtBoxRenderer() = default;
		~PlayerHurtBoxRenderer() = default;

	public:
		void Init(SpriteRenderer* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHurtBox(RB::Players::PlayerID playerID);

	private:
		SpriteRenderer* _spriteRenderer = nullptr;
	};
}