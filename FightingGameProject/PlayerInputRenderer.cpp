#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerInputRenderer::Init(RB::Sprites::Sprites* sprites)
	{
		_sprites = sprites;
	}

	void PlayerInputRenderer::OnUpdate()
	{
		_RenderPlayerInputIcons(RB::Players::PlayerID::PLAYER_1, 50);
		_RenderPlayerInputIcons(RB::Players::PlayerID::PLAYER_2, 100);
	}

	void PlayerInputRenderer::OnFixedUpdate()
	{

	}

	void PlayerInputRenderer::_RenderPlayerInputIcons(RB::Players::PlayerID playerID, int yPos)
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		if (RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		const auto vec = RB::Input::iInputController::instance->GetVecInputObjs(player->GetPlayerID());

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

			if ((*i)->IsUsedAsSpecial())
			{
				tint = olc::YELLOW;
			}

			_RenderIcon(_GetSpriteEnum((*i)->GetPlayerInputType()), olc::vi2d(5 + (count * 30 + 5), yPos), tint);

			count++;
		}
	}

	void PlayerInputRenderer::_RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint)
	{
		_sprites->RenderSprite(spriteEnum, olc::vi2d{ 25, 25 }, pos, tint, RB::Sprites::PivotType::BOTTOM_LEFT, false);
	}

	RB::Sprites::SpriteEnum PlayerInputRenderer::_GetSpriteEnum(const RB::Input::PlayerInput& playerInput)
	{
		if (playerInput == RB::Input::PlayerInput::MOVE_UP) { return RB::Sprites::SpriteEnum::input_arrow_up; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_DOWN) { return RB::Sprites::SpriteEnum::input_arrow_down; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_LEFT) { return RB::Sprites::SpriteEnum::input_arrow_left; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_RIGHT) { return RB::Sprites::SpriteEnum::input_arrow_right; }

		else if (playerInput == RB::Input::PlayerInput::MOVE_UP_LEFT) { return RB::Sprites::SpriteEnum::input_arrow_up_left; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_UP_RIGHT) { return RB::Sprites::SpriteEnum::input_arrow_up_right; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_DOWN_LEFT) { return RB::Sprites::SpriteEnum::input_arrow_down_left; }
		else if (playerInput == RB::Input::PlayerInput::MOVE_DOWN_RIGHT) { return RB::Sprites::SpriteEnum::input_arrow_down_right; }

		else if (playerInput == RB::Input::PlayerInput::ATTACK_WEAK_PUNCH) { return RB::Sprites::SpriteEnum::input_weak_punch; }
		else if (playerInput == RB::Input::PlayerInput::ATTACK_WEAK_KICK) { return RB::Sprites::SpriteEnum::input_weak_kick; }

		return RB::Sprites::SpriteEnum::NONE;
	}
}