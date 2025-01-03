#include "PlayerDebugController.h"
#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerDebugController::Init()
	{
		_spriteContainer.LoadSprite("../resource/PNG files/DebugElements/x_white.png", RB::Sprites::SpriteType::x_white);
		_spriteContainer.LoadSprite("../resource/PNG files/DebugElements/white_sq.png", RB::Sprites::SpriteType::white_sq);
		_spriteContainer.LoadSprite("../resource/PNG files/DebugElements/player_hp_bar_white.png", RB::Sprites::SpriteType::player_hp_bar_white);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_up.png", RB::Sprites::SpriteType::input_arrow_up);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_down.png", RB::Sprites::SpriteType::input_arrow_down);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_left.png", RB::Sprites::SpriteType::input_arrow_left);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_right.png", RB::Sprites::SpriteType::input_arrow_right);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_up_left.png", RB::Sprites::SpriteType::input_arrow_up_left);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_up_right.png", RB::Sprites::SpriteType::input_arrow_up_right);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_down_left.png", RB::Sprites::SpriteType::input_arrow_down_left);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/arrow_down_right.png", RB::Sprites::SpriteType::input_arrow_down_right);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/weak_punch.png", RB::Sprites::SpriteType::input_weak_punch);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/strong_punch.png", RB::Sprites::SpriteType::input_strong_punch);

		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/weak_kick.png", RB::Sprites::SpriteType::input_weak_kick);
		_spriteContainer.LoadSprite("../resource/PNG files/InputIcons/strong_kick.png", RB::Sprites::SpriteType::input_strong_kick);

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

		_RenderBodyParts(RB::Players::PlayerID::PLAYER_1);
		_RenderBodyParts(RB::Players::PlayerID::PLAYER_2);
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

	void PlayerDebugController::_RenderBodyParts(RB::Players::PlayerID id)
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(id);

		if (player == nullptr)
		{
			return;
		}

		RB::Players::iPlayerCollider* col = player->GetPlayerCollider();

		float* parts = col->GetBodyParts();

		RB::Vector2 relLowerBody = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition({ player->GetPosition().x, parts[0]});
		//RB::Vector2 intLowerBody = { int(round(relLowerBody.x)), int(round(relLowerBody.y)) };

		RB::Vector2 relUpperBody = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition({ player->GetPosition().x, parts[1]});
		//RB::Vector2 intUpperBody = { int(round(relUpperBody.x)), int(round(relUpperBody.y)) };

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