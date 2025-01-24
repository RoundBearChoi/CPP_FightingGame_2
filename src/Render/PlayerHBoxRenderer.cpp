#include "PlayerHBoxRenderer.h"

namespace RB::Render
{
    void PlayerHBoxRenderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}
	void PlayerHBoxRenderer::OnUpdate()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		if (playerController == nullptr || playerAnimationController == nullptr)
		{
			return;
		}

		RenderHBox(RB::Players::PlayerID::PLAYER_1, RB::HBox::HBoxType::TARGET_BOX);
		RenderHBox(RB::Players::PlayerID::PLAYER_2, RB::HBox::HBoxType::TARGET_BOX);

		RenderHBox(RB::Players::PlayerID::PLAYER_1, RB::HBox::HBoxType::ATTACK_BOX);
		RenderHBox(RB::Players::PlayerID::PLAYER_2, RB::HBox::HBoxType::ATTACK_BOX);
	}

	void PlayerHBoxRenderer::OnFixedUpdate()
	{

	}

	void PlayerHBoxRenderer::RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType)
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnID(playerID);
		
		if (player == nullptr)
		{
			return;
		}

		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(playerID, spriteType);
		
		if (aniObj == nullptr)
		{
			return;
		}
		
		int currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (RB::HBox::iTargetBoxDataController::Get() != nullptr)
			{
				data = RB::HBox::iTargetBoxDataController::Get()->GetData(spriteType);
			}
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (RB::HBox::iAttackBoxDataController::Get() != nullptr)
			{
				data = RB::HBox::iAttackBoxDataController::Get()->GetData(spriteType);
			}
		}

		if (data == nullptr)
		{
			return;
		}

		RB::HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(currentIndex);

		if (AABBs == nullptr)
		{
			return;
		}

		olc::Pixel tint = olc::RED;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			tint = olc::MAGENTA;
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			tint = olc::GREEN;
		}

		tint.a = 40;

		_Render(player, AABBs, tint);
	}

	void PlayerHBoxRenderer::_Render(RB::Players::iPlayer* player, RB::HBox::AABB_Set* AABBs, olc::Pixel tint)
	{
		const auto& vec = AABBs->GetSelector()->GetVector();

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

			RB::Vector2 pos;
			RB::Sprites::PivotType pivotType;

			if (player->IsFacingRight())
			{
				pos = aabb.GetBottomLeft() + player->GetPosition();

				pivotType = RB::Sprites::PivotType::BOTTOM_LEFT;
				//_spriteContainer->RenderSprite(RB::Sprites::SpriteType::white_sq, aabb.GetWidthHeight().x, aabb.GetWidthHeight().y, pos, color, RB::Sprites::PivotType::BOTTOM_LEFT, true);
			}
			else
			{
				RB::Vector2 bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				pos = bottomleft + player->GetPosition();

				pivotType = RB::Sprites::PivotType::BOTTOM_RIGHT;
				//_spriteContainer->RenderSprite(RB::Sprites::SpriteType::white_sq, aabb.GetWidthHeight().x, aabb.GetWidthHeight().y, pos, color, RB::Sprites::PivotType::BOTTOM_RIGHT, true);
			}

			_spriteContainer->RenderSprite(
				RB::Sprites::SpriteType::white_sq, 
				aabb.GetWidthHeight().x, 
				aabb.GetWidthHeight().y, 
				pos, 
				tint, 
				pivotType, 
				true);
		}
	}
}
