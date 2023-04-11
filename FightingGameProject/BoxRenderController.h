#pragma once
#include "iBoxRenderController.h"
#include "BoxRenderer.h"

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

	private:
		BoxRenderer _boxRenderer;
	};
}