#include "RenderTimer.h"

namespace RB
{
	void RenderTimer::OnUpdate()
	{
		_accumulated += RB::Time::GetDeltaTime();

		_counter++;

		if (_accumulated >= 1.0f)
		{
			_lastCount = _counter;
			_counter = 0;
			_accumulated = 0.0f;
		}

		olc::Renderer::ptrPGE->DrawStringDecal({ 8, 12 }, "Update Count: " + std::to_string(_lastCount), olc::WHITE, { 0.65f, 0.65f });
	}
}
