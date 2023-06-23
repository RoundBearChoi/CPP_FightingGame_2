#pragma once
#include "SpriteRenderer.h"
#include "AABB.h"

#include "ActivePlayerStates.h"

#include "ControllerGetter.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"

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