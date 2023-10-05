#pragma once
#include "SpriteRenderer.h"

#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(SpriteObj* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		SpriteObj* _spriteObj = nullptr;
	};
}