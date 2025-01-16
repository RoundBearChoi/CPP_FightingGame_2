#pragma once

namespace RB
{
	class Time
	{
	public:
		Time() = delete;
		~Time() = delete;

	private:
		static float _deltaTime;
		//static float _fixedDeltaTime;

	public:
		static void SetDeltaTime(float delta);
		//static void AddFixedDeltaTime();
		//static void ResetFixedDeltaTime();
		static float GetDeltaTime();
		//static float GetFixedDeltaTime();
	};
}