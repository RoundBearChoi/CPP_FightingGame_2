#pragma once

#include "olcPixelGameEngine.h"

#include "Time.h"

namespace RB
{
	class UpdateCounter
	{
	public:
		void OnUpdate();

	private:
		int _counter = 0;
		int _lastCount = 0;
		float _accumulated = 0.0f;
	};
}
