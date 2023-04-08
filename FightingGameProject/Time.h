#pragma once

namespace RB::Frames
{
	class Time
	{
	private:
		static float _deltaTime;

	public:
		static void SetDeltaTime(float delta);
		static float GetDeltaTime();
	};
}