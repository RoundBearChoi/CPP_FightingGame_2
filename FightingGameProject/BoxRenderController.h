#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "PivotType.h"
#include "iBoxRenderController.h"
#include "iBoxRenderer.h"
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

	public:
		iBoxRenderer* GetBoxRenderer() override;

	private:
		iBoxRenderer* _boxRenderer = nullptr;
	};
}