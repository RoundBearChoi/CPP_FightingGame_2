#include "PlayerHBoxRenderer.h"

namespace RB::Render
{
    void PlayerHBoxRenderer::Init(RB::Sprites::SpriteLoader* sprites)
	{
		_sprites = sprites;
	}
	void PlayerHBoxRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Render::iPlayerAnimationController::instance == nullptr)
		{
			return;
		}

		RenderHBox(RB::Players::PlayerID::PLAYER_1, RB::HBox::HBoxType::HURT_BOX);
		RenderHBox(RB::Players::PlayerID::PLAYER_2, RB::HBox::HBoxType::HURT_BOX);

		RenderHBox(RB::Players::PlayerID::PLAYER_1, RB::HBox::HBoxType::HIT_BOX);
		RenderHBox(RB::Players::PlayerID::PLAYER_2, RB::HBox::HBoxType::HIT_BOX);
	}

	void PlayerHBoxRenderer::OnFixedUpdate()
	{

	}

	void PlayerHBoxRenderer::RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);
		
		if (player == nullptr)
		{
			return;
		}

		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		iAnimationObj* aniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(playerID, spriteEnum);
		
		if (aniObj == nullptr)
		{
			return;
		}
		
		int currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::HBox_Layer_1* L1 = nullptr;

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::iHurtBoxDataController::instance != nullptr)
			{
				L1 = RB::HBox::iHurtBoxDataController::instance->Get_L1(spriteEnum);
			}
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance != nullptr)
			{
				L1 = RB::HBox::iHitBoxDataController::instance->Get_L1(spriteEnum);
			}
		}

		if (L1 == nullptr)
		{
			return;
		}

		RB::HBox::HBox_Layer_0* L0 = L1->GetHBoxDataByFrame(currentIndex);

		if (L0 == nullptr)
		{
			return;
		}

		olc::Pixel color = olc::RED;

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			color = olc::MAGENTA;
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			color = olc::GREEN;
		}

		_Render(player, L0, color);
	}

	void PlayerHBoxRenderer::_Render(RB::Players::iPlayer* player, RB::HBox::HBox_Layer_0* L0, olc::Pixel color)
	{
		const auto& vec = L0->GetSelector()->GetVector();

		for (auto i = vec.begin(); i != vec.end(); ++i) 
		{
			RB::Collisions::AABB aabb = (*i);

			if (aabb.GetWidthHeight().x <= 0.001f)
			{
				continue;
			}

			if (aabb.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			if (player->OtherPlayerIsOnRightSide())
			{
				olc::vf2d pos = aabb.GetBottomLeft() + player->GetPosition();

				_sprites->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, color, RB::Sprites::PivotType::BOTTOM_LEFT);
			}
			else
			{
				olc::vf2d bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				olc::vf2d pos = bottomleft + player->GetPosition();

				_sprites->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, color, RB::Sprites::PivotType::BOTTOM_RIGHT);
			}
		}
	}
}