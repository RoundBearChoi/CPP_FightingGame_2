#pragma once
#include "SpriteRenderer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

namespace RB::Render
{
	class PlayerPositionRenderer
	{
	public:
		PlayerPositionRenderer() = default;
		~PlayerPositionRenderer() = default;

	public:
		void Init(SpriteRenderer* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PlayerID playerID);

	private:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;

	private:
		SpriteRenderer* _spriteRenderer = nullptr;
	};
}
