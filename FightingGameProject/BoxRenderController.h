#pragma once
#include "iBoxRenderController.h"
#include "iDebugRenderer.h"
#include "SpriteRenderer.h"

namespace RB::Render
{
	class BoxRenderController : public iBoxRenderController
	{
	public:
		BoxRenderController();
		~BoxRenderController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		iDebugRenderer* GetBoxRenderer() override;

	private:
		iDebugRenderer* _spriteRenderer = nullptr;
	};
}