#pragma once
#include <vector>
#include "ControllerBase.h"
#include "BackgroundObj.h"

namespace RB::Background
{
	class BackgroundController : public RB::Controllers::ControllerBase
	{
	public:
		BackgroundController();
		~BackgroundController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		std::vector<BackgroundObj*> _vecBackgroundObjs;
	};
}