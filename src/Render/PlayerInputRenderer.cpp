#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerInputRenderer::Init(Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void PlayerInputRenderer::OnUpdate()
	{
		if (_render)
		{
			_RenderPlayerInputIcons(Players::PLAYER_TYPE::PLAYER_1, 45);
			_RenderPlayerInputIcons(Players::PLAYER_TYPE::PLAYER_2, 70);
		}
	}

	void PlayerInputRenderer::OnFixedUpdate()
	{

	}

	void PlayerInputRenderer::RenderInput(bool render)
	{
		_render = render;
	}

	void PlayerInputRenderer::_RenderPlayerInputIcons(Players::PLAYER_TYPE playerID, int yPos)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		if (inputController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayer(playerID);

		if (player == nullptr)
		{
			return;
		}

		const auto vec = inputController->GetVecInputObjs(player->GetPLAYER_TYPE());

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

	void PlayerInputRenderer::_RenderIcon(Sprites::SpriteType spriteType, RB::Vector2 pos, olc::Pixel tint)
	{
		_spriteContainer->RenderSprite(
			spriteType, 
			17, 
			17 , 
			pos, 
			tint, 
			Sprites::PivotType::BOTTOM_LEFT, 
			false);
	}

	Sprites::SpriteType PlayerInputRenderer::_GetSpriteType(const RB::Input::PlayerInput& playerInput)
	{
		if (playerInput._value == RB::Input::PlayerInput::MOVE_UP) { return Sprites::SpriteType::input_arrow_up; }
		else if (playerInput._value == RB::Input::PlayerInput::MOVE_DOWN) { return Sprites::SpriteType::input_arrow_down; }
		else if (playerInput._value == RB::Input::PlayerInput::MOVE_LEFT) { return Sprites::SpriteType::input_arrow_left; }
		else if (playerInput._value == RB::Input::PlayerInput::MOVE_RIGHT) { return Sprites::SpriteType::input_arrow_right; }

		else if (playerInput._value == RB::Input::PlayerInput::MOVE_UP_LEFT) { return Sprites::SpriteType::input_arrow_up_left; }
		else if (playerInput._value == RB::Input::PlayerInput::MOVE_UP_RIGHT) { return Sprites::SpriteType::input_arrow_up_right; }
		else if (playerInput._value == RB::Input::PlayerInput::MOVE_DOWN_LEFT) { return Sprites::SpriteType::input_arrow_down_left; }
		else if (playerInput._value == RB::Input::PlayerInput::MOVE_DOWN_RIGHT) { return Sprites::SpriteType::input_arrow_down_right; }

		else if (playerInput._value == RB::Input::PlayerInput::ATTACK_WEAK_PUNCH) { return Sprites::SpriteType::input_weak_punch; }
		else if (playerInput._value == RB::Input::PlayerInput::ATTACK_STRONG_PUNCH) { return Sprites::SpriteType::input_strong_punch; }

		else if (playerInput._value == RB::Input::PlayerInput::ATTACK_WEAK_KICK) { return Sprites::SpriteType::input_weak_kick; }
		else if (playerInput._value == RB::Input::PlayerInput::ATTACK_STRONG_KICK) { return Sprites::SpriteType::input_strong_kick; }

		return Sprites::SpriteType::NONE;
	}
}
