#pragma once
#include "SpriteObj.h"

#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(Sprites* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		Sprites* _spriteObj = nullptr;
	};
}