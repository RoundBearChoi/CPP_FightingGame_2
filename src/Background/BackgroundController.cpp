#include "BackgroundController.h"

#include "../Logger/iLogController.h"

namespace RB::Background
{
	BackgroundController::~BackgroundController()
	{
		for (auto i = _vecBackgroundObjs.begin(); i != _vecBackgroundObjs.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}
	}

	void BackgroundController::Init()
	{
		auto logController = GET_LOG_CONTROLLER;

		logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_SPRITE, "loading background sprites");

		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_01.png", Sprites::SPRITE_TYPE::background_1, 0.90f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_02.png", Sprites::SPRITE_TYPE::background_2, 0.80f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_03.png", Sprites::SPRITE_TYPE::background_3, 0.70f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_04.png", Sprites::SPRITE_TYPE::background_4, 0.45f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_05.png", Sprites::SPRITE_TYPE::background_5, 0.30f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_06.png", Sprites::SPRITE_TYPE::background_6, 0.15f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_07.png", Sprites::SPRITE_TYPE::background_7, 0.08f));
		_vecBackgroundObjs.push_back(new BackgroundObj("../resource/PNG files/StringStar/stringstar_08.png", Sprites::SPRITE_TYPE::background_8, 0.0f));
	}

	void BackgroundController::OnUpdate()
	{
		Render::SetTargetLayer(Render::RenderLayerType::DECALS);

		for (auto i = _vecBackgroundObjs.begin(); i != _vecBackgroundObjs.end(); i++)
		{
			(*i)->OnUpdate();
		}

		Render::ClearTargetLayer();
	}

	void BackgroundController::OnFixedUpdate()
	{
		for (auto i = _vecBackgroundObjs.begin(); i != _vecBackgroundObjs.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}
}
