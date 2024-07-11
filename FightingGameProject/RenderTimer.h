#pragma once

namespace RB::Frames
{
	class RenderTimer
	{
	public:
		void OnUpdate();

	private:
		int _counter = 0;
		int _lastCount = 0;
		float _accumulated = 0.0f;
	};
}
