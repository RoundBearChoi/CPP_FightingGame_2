#include "Notification.h"

#include "olcPixelGameEngine.h"

namespace RB::Render
{
	void Notification::OnUpdate(const std::string& message)
	{
		if (_frameCount > 0)
		{
			olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 170 }, message, olc::GREEN, { 0.85f, 0.85f });
		}
	}

	void Notification::OnFixedUpdate()
	{
		if (_frameCount > 0)
		{
			_frameCount--;
		}
	}

	unsigned int Notification::GetFrameCount()
	{
		return _frameCount;
	}

	void Notification::AddFrameCount(unsigned int frameCount)
	{
		_frameCount = frameCount;
	}
}
