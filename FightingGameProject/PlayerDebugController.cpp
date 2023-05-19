#include "PlayerDebugController.h"

namespace RB::Render
{
	PlayerDebugController::PlayerDebugController()
	{
		SetHash(typeid(*this));
	}

	void PlayerDebugController::Init()
	{
		//sprite renderer
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteEnum::x_white);
		_spriteRenderer.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteEnum::white_sq_tr80);

		//line renderer
		_lineRenderer.Init();

		_playerColliderBoxRenderer.Init(&_spriteRenderer);
	}

	void PlayerDebugController::OnUpdate()
	{
		_getter_playerController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* p1 = _getter_playerController.GetController()->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = _getter_playerController.GetController()->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		if (p1 != nullptr)
		{
			//DrawPlayerBox(p1);
			DrawPlayerPosition(p1);
			DrawPlayerAirMomentum(p1);
		}

		if (p2 != nullptr)
		{
			//DrawPlayerBox(p2);
			DrawPlayerPosition(p2);
			DrawPlayerAirMomentum(p2);
		}

		_playerColliderBoxRenderer.OnUpdate();
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		_playerColliderBoxRenderer.OnFixedUpdate();
	}

	void PlayerDebugController::DrawPlayerPosition(RB::Players::iPlayer* player)
	{
		olc::vi2d playerPos = player->GetPosition();

		_spriteRenderer.RenderSprite(RB::Sprites::SpriteEnum::x_white, olc::vi2d{ 13, 13 }, playerPos, olc::RED, RB::Sprites::PivotType::CENTER);
	}

	void PlayerDebugController::DrawPlayerBottomLeft(RB::Players::iPlayer* player)
	{
		RB::Collisions::AABB aabb = player->GetAABB();

		_lineRenderer.RenderLine(aabb.GetBottomLeft() - olc::vi2d{ 15, 0 }, aabb.GetBottomLeft(), olc::RED);
	}

	void PlayerDebugController::DrawPlayerAirMomentum(RB::Players::iPlayer* player)
	{
		olc::vi2d pos = player->GetPosition();
		olc::vf2d airMomentum = player->GetAirMomentum();

		if (airMomentum.y > 0.5f)
		{
			int32_t boxY = player->GetPlayerBox().y;

			pos.y -= boxY;

			_lineRenderer.RenderLine(pos, pos - player->GetAirMomentum(), olc::CYAN);
		}
	}
}