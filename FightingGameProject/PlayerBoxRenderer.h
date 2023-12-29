#pragma once
#include "Sprites.h"

#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(RB::Sprites::Sprites* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		RB::Sprites::Sprites* _sprites = nullptr;
	};
}