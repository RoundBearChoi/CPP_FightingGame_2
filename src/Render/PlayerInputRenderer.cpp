#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerInputRenderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void PlayerInputRenderer::OnUpdate()
	{
		if (_render)
		{
			_RenderPlayerInputIcons(RB::Players::PlayerID::PLAYER_1, 45);
			_RenderPlayerInputIcons(RB::Players::PlayerID::PLAYER_2, 70);
		}
	}

	void PlayerInputRenderer::OnFixedUpdate()
	{

	}

	void PlayerInputRenderer::RenderInput(bool render)
	{
		_render = render;
	}

	void PlayerInputRenderer::_RenderPlayerInputIcons(RB::Players::PlayerID playerID, int yPos)
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		if (RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = playerController->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		const auto vec = RB::Input::iInputController::Get()->GetVecInputObjs(player->GetPlayerID());

		int count = 0;

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if ((*i) == nullptr)
			{
				continue;
			}

			olc::Pixel tint = olc::WHITE;

			if ((*i)->IsReleased())
			{
				tint = olc::GREY;
			}

			if ((*i)->IsUsedAsMovement())
			{
				tint = olc::BLUE;
			}

			if ((*i)->IsUsedAsAttack())
			{
				tint = olc::YELLOW;
			}

			_RenderIcon(_GetSpriteType((*i)->GetPlayerInputType()), RB::Vector2(5 + (count * 21 + 3), yPos), tint);

			count++;
		}
	}

	void PlayerInputRenderer::_RenderIcon(RB::Sprites::SpriteType spriteType, RB::Vector2 pos, olc::Pixel tint)
	{
		_spriteContainer->RenderSprite(
			spriteType, 
			17, 
			17 , 
			pos, 
			tint, 
			RB::Sprites::PivotType::BOTTOM_LEFT, 
			false);
	}

	RB::Sprites::SpriteType PlayerInputRenderer::_GetSpriteType(const RB::Input::PlayerInput& playerInput)
	{
		if (playerInput == RB::Input::PlayerInput::MOVE_UP) { return RB::Sprites::SpriteType::input_arrow_up; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_DOWN) { return RB::Sprites::SpriteType::input_arrow_down; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_LEFT) { return RB::Sprites::SpriteType::input_arrow_left; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_RIGHT) { return RB::Sprites::SpriteType::input_arrow_right; }

		else if (playerInput == RB::Input::PlayerInput::MOVE_UP_LEFT) { return RB::Sprites::SpriteType::input_arrow_up_left; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_UP_RIGHT) { return RB::Sprites::SpriteType::input_arrow_up_right; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_DOWN_LEFT) { return RB::Sprites::SpriteType::input_arrow_down_left; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_DOWN_RIGHT) { return RB::Sprites::SpriteType::input_arrow_down_right; }

		else if (playerInput == RB::Input::PlayerInput::ATTACK_WEAK_PUNCH) { return RB::Sprites::SpriteType::input_weak_punch; }
		else if (playerInput == RB::Input::PlayerInput::ATTACK_STRONG_PUNCH) { return RB::Sprites::SpriteType::input_strong_punch; }

		else if (playerInput == RB::Input::PlayerInput::ATTACK_WEAK_KICK) { return RB::Sprites::SpriteType::input_weak_kick; }
		else if (playerInput == RB::Input::PlayerInput::ATTACK_STRONG_KICK) { return RB::Sprites::SpriteType::input_strong_kick; }

		return RB::Sprites::SpriteType::NONE;
	}
}
