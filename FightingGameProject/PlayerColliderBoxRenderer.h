#pragma once
#include "SpriteRenderer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

namespace RB::Render
{
	class PlayerColliderBoxRenderer
	{
	public:
		PlayerColliderBoxRenderer() = default;
		~PlayerColliderBoxRenderer() = default;

	public:
		void Init(SpriteRenderer* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		SpriteRenderer* _spriteRenderer = nullptr;

	private:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
	};
}