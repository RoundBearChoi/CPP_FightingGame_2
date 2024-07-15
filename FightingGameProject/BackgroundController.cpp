#include "BackgroundController.h"

#include "RenderLayerType.h"

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
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_01.png", RB::Sprites::SpriteType::background_1, 0.90f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_02.png", RB::Sprites::SpriteType::background_2, 0.80f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_03.png", RB::Sprites::SpriteType::background_3, 0.70f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_04.png", RB::Sprites::SpriteType::background_4, 0.45f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_05.png", RB::Sprites::SpriteType::background_5, 0.30f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_06.png", RB::Sprites::SpriteType::background_6, 0.15f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_07.png", RB::Sprites::SpriteType::background_7, 0.08f));
		_vecBackgroundObjs.push_back(new BackgroundObj("PNG files/StringStar/stringstar_08.png", RB::Sprites::SpriteType::background_8, 0.0f));
	}

	void BackgroundController::OnUpdate()
	{
		RB::Render::SetTargetLayer(RB::Render::RenderLayerType::DECALS);

		for (auto i = _vecBackgroundObjs.begin(); i != _vecBackgroundObjs.end(); i++)
		{
			(*i)->OnUpdate();
		}
	}

	void BackgroundController::OnFixedUpdate()
	{
		for (auto i = _vecBackgroundObjs.begin(); i != _vecBackgroundObjs.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}
}
