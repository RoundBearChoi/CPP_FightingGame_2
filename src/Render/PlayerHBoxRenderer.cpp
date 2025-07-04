#include "PlayerHBoxRenderer.h"

namespace RB::Render
{
    void PlayerHBoxRenderer::Init(Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}
	void PlayerHBoxRenderer::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		if (playerController == nullptr || playerAnimationController == nullptr)
		{
			return;
		}

		RenderHBox(Players::PLAYER_TYPE::PLAYER_1, RB::HBox::HBoxType::TARGET_BOX);
		RenderHBox(Players::PLAYER_TYPE::PLAYER_2, RB::HBox::HBoxType::TARGET_BOX);

		RenderHBox(Players::PLAYER_TYPE::PLAYER_1, RB::HBox::HBoxType::ATTACK_BOX);
		RenderHBox(Players::PLAYER_TYPE::PLAYER_2, RB::HBox::HBoxType::ATTACK_BOX);
	}

	void PlayerHBoxRenderer::OnFixedUpdate()
	{

	}

	void PlayerHBoxRenderer::RenderHBox(Players::PLAYER_TYPE playerID, RB::HBox::HBoxType boxType)
	{
		auto playerController = GET_PLAYER_CONTROLLER;
		auto playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(playerID);
		
		if (player == nullptr)
		{
			return;
		}

		Players::PlayerState* state = Players::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return;
		}

		Sprites::SpriteType spriteType = state->GetSpriteType();

		iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(playerID, spriteType);
		
		if (aniObj == nullptr)
		{
			return;
		}
		
		int currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (targetBoxDataController != nullptr)
			{
				data = targetBoxDataController->GetData(spriteType);
			}
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (attackBoxDataController != nullptr)
			{
				data = attackBoxDataController->GetData(spriteType);
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

	void PlayerHBoxRenderer::_Render(Players::iPlayer* player, RB::HBox::AABB_Set* AABBs, olc::Pixel tint)
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
			Sprites::PivotType pivotType;

			if (player->IsFacingRight())
			{
				pos = aabb.GetBottomLeft() + player->GetPosition();

				pivotType = Sprites::PivotType::BOTTOM_LEFT;
				//_spriteContainer->RenderSprite(Sprites::SpriteType::white_sq, aabb.GetWidthHeight().x, aabb.GetWidthHeight().y, pos, color, Sprites::PivotType::BOTTOM_LEFT, true);
			}
			else
			{
				RB::Vector2 bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				pos = bottomleft + player->GetPosition();

				pivotType = Sprites::PivotType::BOTTOM_RIGHT;
				//_spriteContainer->RenderSprite(Sprites::SpriteType::white_sq, aabb.GetWidthHeight().x, aabb.GetWidthHeight().y, pos, color, Sprites::PivotType::BOTTOM_RIGHT, true);
			}

			_spriteContainer->RenderSprite(
				Sprites::SpriteType::white_sq, 
				aabb.GetWidthHeight().x, 
				aabb.GetWidthHeight().y, 
				pos, 
				tint, 
				pivotType, 
				true);
		}
	}
}
