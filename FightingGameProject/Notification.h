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
		void ShowNotification(unsigned int frameCount);

	private:
		std::string _fileSaved = "File saved: ";
		int _notificationFrameCount = 0;
	};
}