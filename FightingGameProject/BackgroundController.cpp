#include "BackgroundController.h"

namespace RB::Background
{
	BackgroundController::BackgroundController()
	{
		SetHash(typeid(*this));
	}

	BackgroundController::~BackgroundController()
	{
		for (size_t i = 0; i < _vecBackgroundObjs.size(); i++)
		{
			delete _vecBackgroundObjs[i];
		}
	}

	void BackgroundController::Init()
	{
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/Backgrounds/background_0.png", RB::Sprites::SpriteEnum::background_0, olc::vf2d{ 0.0f, 0.0f }, 1.0f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/Backgrounds/background_1.png", RB::Sprites::SpriteEnum::background_1, olc::vf2d{ 0.0f, 0.0f }, 1.0f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/Backgrounds/background_2.png", RB::Sprites::SpriteEnum::background_2, olc::vf2d{ 0.0f, 0.0f }, 1.0f));
	}

	void BackgroundController::OnUpdate()
	{
		for (size_t i = 0; i < _vecBackgroundObjs.size(); i++)
		{
			_vecBackgroundObjs[i]->OnUpdate();
		}
	}

	void BackgroundController::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecBackgroundObjs.size(); i++)
		{
			_vecBackgroundObjs[i]->OnFixedUpdate();
		}
	}
}