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
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_01.png", RB::Sprites::SpriteEnum::background_1, 0.84f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_02.png", RB::Sprites::SpriteEnum::background_2, 0.72f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_03.png", RB::Sprites::SpriteEnum::background_3, 0.60f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_04.png", RB::Sprites::SpriteEnum::background_4, 0.48f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_05.png", RB::Sprites::SpriteEnum::background_5, 0.36f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_06.png", RB::Sprites::SpriteEnum::background_6, 0.24f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_07.png", RB::Sprites::SpriteEnum::background_7, 0.12f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_08.png", RB::Sprites::SpriteEnum::background_8, 0.0f));
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