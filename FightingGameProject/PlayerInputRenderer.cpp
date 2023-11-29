#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerInputRenderer::Init(Sprites* sprites)
	{
		_sprites = sprites;
	}

	void PlayerInputRenderer::OnUpdate()
	{
		_RenderPlayerInputIcons(RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1));
	}

	void PlayerInputRenderer::OnFixedUpdate()
	{

	}

	void PlayerInputRenderer::_RenderPlayerInputIcons(RB::Players::iPlayer* player)
	{
		size_t count = RB::Input::INPUT_CONTROLLER->GetTotalInputCount(player->GetPlayerID());

		for (size_t i = 0; i < count; i++)
		{
			RB::Input::iInputObj* inputObj = RB::Input::INPUT_CONTROLLER->GetInputByIndex(player->GetPlayerID(), i);

			olc::Pixel tint = olc::WHITE;

			if (inputObj->IsReleased())
			{
				tint = olc::DARK_GREY;
			}

			_RenderIcon(_GetSpriteEnum(inputObj->GetPlayerInputType()), olc::vi2d(5 + (i * 30 + 5), 50), tint);
		}
	}

	void PlayerInputRenderer::_RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint)
	{
		_sprites->RenderSprite(spriteEnum, olc::vi2d{ 28, 28 }, pos, tint, RB::Sprites::PivotType::BOTTOM_LEFT, false);
	}

	RB::Sprites::SpriteEnum PlayerInputRenderer::_GetSpriteEnum(const RB::Input::PlayerInput& playerInput)
	{
		if (playerInput == RB::Input::PlayerInput::MOVE_LEFT)
		{
			return RB::Sprites::SpriteEnum::input_arrow_left;
		}
		else if (playerInput == RB::Input::PlayerInput::MOVE_RIGHT)
		{
			return RB::Sprites::SpriteEnum::input_arrow_right;
		}
		else if (playerInput == RB::Input::PlayerInput::JUMP)
		{
			return RB::Sprites::SpriteEnum::input_arrow_up;
		}
		else if (playerInput == RB::Input::PlayerInput::ATTACK_WEAK_PUNCH)
		{
			return RB::Sprites::SpriteEnum::input_weak_punch;
		}
		else if (playerInput == RB::Input::PlayerInput::ATTACK_WEAK_KICK)
		{
			return RB::Sprites::SpriteEnum::input_weak_kick;
		}

		return RB::Sprites::SpriteEnum::NONE;
	}
}