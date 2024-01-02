#include "Notification.h"

#include "olcPixelGameEngine.h"

namespace RB::Render
{
	void Notification::Init()
	{
	}
	void Notification::OnUpdate(const std::string& message)
	{
		if (_notificationFrameCount > 0)
		{
			olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 200 }, _fileSaved + message, olc::GREEN);
		}
	}

	void Notification::OnFixedUpdate()
	{
		if (_notificationFrameCount > 0)
		{
			_notificationFrameCount--;
		}
	}

	void Notification::ShowNotification(unsigned int frameCount)
	{
		_notificationFrameCount = frameCount;
	}
}