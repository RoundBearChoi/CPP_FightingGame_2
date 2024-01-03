#pragma once

#include <string>

namespace RB::Render
{
	class Notification
	{
	public:
		Notification() = default;
		~Notification() = default;

		void Init();
		void OnUpdate(const std::string& message);
		void OnFixedUpdate();

	public:
		unsigned int GetFrameCount();
		void AddFrameCount(unsigned int frameCount);

	private:
		int _frameCount = 0;
	};
}