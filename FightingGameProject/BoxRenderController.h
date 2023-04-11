#pragma once
#include "iBoxRenderController.h"
#include "iBoxRenderer.h"
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
		iBoxRenderer* GetBoxRenderer() override;

	private:
		iBoxRenderer* _spriteRenderer = nullptr;
	};
}