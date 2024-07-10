#include "PlayerDebugController.h"

#include "RenderLayerType.h"

#include "iCamController.h"

namespace RB::Render
{
	void PlayerDebugController::Init()
	{
		_spriteContainer.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteType::x_white);
		_spriteContainer.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteType::white_sq_tr80);

		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_up.png", RB::Sprites::SpriteType::input_arrow_up);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_down.png", RB::Sprites::SpriteType::input_arrow_down);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_left.png", RB::Sprites::SpriteType::input_arrow_left);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_right.png", RB::Sprites::SpriteType::input_arrow_right);

		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_up_left.png", RB::Sprites::SpriteType::input_arrow_up_left);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_up_right.png", RB::Sprites::SpriteType::input_arrow_up_right);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_down_left.png", RB::Sprites::SpriteType::input_arrow_down_left);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_down_right.png", RB::Sprites::SpriteType::input_arrow_down_right);

		_spriteContainer.LoadSprite("PNG files/InputIcons/weak_punch.png", RB::Sprites::SpriteType::input_weak_punch);
		_spriteContainer.LoadSprite("PNG files/InputIcons/strong_punch.png", RB::Sprites::SpriteType::input_strong_punch);

		_spriteContainer.LoadSprite("PNG files/InputIcons/weak_kick.png", RB::Sprites::SpriteType::input_weak_kick);
		_spriteContainer.LoadSprite("PNG files/InputIcons/strong_kick.png", RB::Sprites::SpriteType::input_strong_kick);

		_playerBoxRenderer.Init(&_spriteContainer);
		_playerHBoxRenderer.Init(&_spriteContainer);
		_playerPositionRenderer.Init(&_spriteContainer, &_lineRenderer);
		_playerInputRenderer.Init(&_spriteContainer);
	}

	void PlayerDebugController::OnUpdate()
	{
		SetTargetLayer(RB::Render::RenderLayerType::DECALS);

		_playerBoxRenderer.OnUpdate();
		_playerHBoxRenderer.OnUpdate();
		_playerPositionRenderer.OnUpdate();
		_playerInputRenderer.OnUpdate();

		_RenderBodyParts(RB::Players::PlayerID::PLAYER_1);
		_RenderBodyParts(RB::Players::PlayerID::PLAYER_2);
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		_playerBoxRenderer.OnFixedUpdate();
		_playerHBoxRenderer.OnFixedUpdate();
		_playerPositionRenderer.OnFixedUpdate();
		_playerInputRenderer.OnFixedUpdate();
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

		olc::vf2d relLowerBody = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition({ player->GetPosition().x, parts[0]});
		olc::vi2d intLowerBody = { int(round(relLowerBody.x)), int(round(relLowerBody.y)) };

		olc::vf2d relUpperBody = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition({ player->GetPosition().x, parts[1]});
		olc::vi2d intUpperBody = { int(round(relUpperBody.x)), int(round(relUpperBody.y)) };

		int lineHalfLength = 30;

		olc::Renderer::ptrPGE->DrawLine(intLowerBody - olc::vi2d{ lineHalfLength, 0 }, intLowerBody + olc::vi2d{ lineHalfLength, 0 }, olc::RED);
		olc::Renderer::ptrPGE->DrawLine(intUpperBody - olc::vi2d{ lineHalfLength, 0 }, intUpperBody + olc::vi2d{ lineHalfLength, 0 }, olc::RED);
	}
}
