#pragma once
#include "iDebugRenderController.h"
#include "iSpriteRenderer.h"
#include "SpriteRenderer.h"

namespace RB::Render
{
	class BoxRenderController : public iDebugRenderController
	{
	public:
		BoxRenderController();
		~BoxRenderController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		iSpriteRenderer* GetBoxRenderer() override;

	private:
		iSpriteRenderer* _spriteRenderer = nullptr;
	};
}