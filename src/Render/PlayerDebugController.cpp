#include "PlayerDebugController.h"

#include "PlayerInputRenderer.h"

#include "../Cam/GetRelPos.h"

#include "../Logger/iLogController.h"

namespace RB::Render
{
	void PlayerDebugController::Init()
	{
		auto logController = GET_LOG_CONTROLLER;

		logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_SPRITE, "loading debug sprites");

		_spriteContainer.LoadSprite("../resource/PNG files/DebugElements/x_white.png", Sprites::SpriteType::x_white);
		_spriteContainer.LoadSprite("../resource/PNG files/DebugElements/white_sq.png", Sprites::SpriteType::white_sq);
		_spriteContainer.LoadSprite("../resource/PNG files/DebugElements/player_hp_bar_white.png", Sprites::SpriteType::player_hp_bar_white);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_up.png", Sprites::SpriteType::input_arrow_up);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_down.png", Sprites::SpriteType::input_arrow_down);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_left.png", Sprites::SpriteType::input_arrow_left);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_right.png", Sprites::SpriteType::input_arrow_right);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_up_left.png", Sprites::SpriteType::input_arrow_up_left);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_up_right.png", Sprites::SpriteType::input_arrow_up_right);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_down_left.png", Sprites::SpriteType::input_arrow_down_left);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_down_right.png", Sprites::SpriteType::input_arrow_down_right);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/weak_punch.png", Sprites::SpriteType::input_weak_punch);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/strong_punch.png", Sprites::SpriteType::input_strong_punch);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/weak_kick.png", Sprites::SpriteType::input_weak_kick);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/strong_kick.png", Sprites::SpriteType::input_strong_kick);

		_playerBoxRenderer.Init(&_spriteContainer);
		_playerHBoxRenderer.Init(&_spriteContainer);
		_playerPositionRenderer.Init(&_spriteContainer, &_lineRenderer);
		_playerInputRenderer.Init(&_spriteContainer);
		_player_HP_Renderer.Init(&_spriteContainer);
	}

	void PlayerDebugController::OnUpdate()
	{
		if (!RB::showDebugRenders)
		{
			return;
		}

		_playerBoxRenderer.OnUpdate();
		_playerHBoxRenderer.OnUpdate();
		_playerPositionRenderer.OnUpdate();
		_playerInputRenderer.OnUpdate();
		_player_HP_Renderer.OnUpdate();

		_RenderBodyParts(Players::PLAYER_TYPE::PLAYER_1);
		_RenderBodyParts(Players::PLAYER_TYPE::PLAYER_2);
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		if (!RB::showDebugRenders)
		{
			return;
		}

		_playerBoxRenderer.OnFixedUpdate();
		_playerHBoxRenderer.OnFixedUpdate();
		_playerPositionRenderer.OnFixedUpdate();
		_playerInputRenderer.OnFixedUpdate();
		_player_HP_Renderer.OnFixedUpdate();
	}

	void PlayerDebugController::RenderPlayerBox(bool render)
	{
		_playerBoxRenderer.RenderPlayerBox(render);
	}

	void PlayerDebugController::RenderPlayerHP(bool render)
	{
		_player_HP_Renderer.RenderHP(render);
	}

	void PlayerDebugController::RenderInput(bool render)
	{
		_playerInputRenderer.RenderInput(render);
	}

	void PlayerDebugController::_RenderBodyParts(Players::PLAYER_TYPE id)
	{
		auto playerController = GET_PLAYER_CONTROLLER;
		auto camController = GET_CAM_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayer(id);

		if (player == nullptr)
		{
			return;
		}

		Players::iPlayerCollider* col = player->GetPlayerCollider();

		float* parts = col->GetBodyParts();

		RB::Vector2 relLowerBody = RB::Cam::GetRelPos(camController->GetCamObj(), { player->GetPosition().x, parts[0]}); //->GetRelativePosition({ player->GetPosition().x, parts[0]});

		RB::Vector2 relUpperBody = RB::Cam::GetRelPos(camController->GetCamObj(), { player->GetPosition().x, parts[1]}); //->GetRelativePosition({ player->GetPosition().x, parts[1]});

		int lineHalfLength = 30;

		olc::Renderer::ptrPGE->DrawLine(
			olc::vi2d{ relLowerBody.GetIntX(), relLowerBody.GetIntY() } - olc::vi2d{ lineHalfLength, 0 },
			olc::vi2d{ relLowerBody.GetIntX(), relLowerBody.GetIntY() } + olc::vi2d{ lineHalfLength, 0 },
			olc::RED);

		olc::Renderer::ptrPGE->DrawLine(
			olc::vi2d{ relUpperBody.GetIntX(), relUpperBody.GetIntY() } - olc::vi2d{ lineHalfLength, 0 },
			olc::vi2d{ relUpperBody.GetIntX(), relUpperBody.GetIntY() } + olc::vi2d{ lineHalfLength, 0 },
			olc::RED);
	}
}
