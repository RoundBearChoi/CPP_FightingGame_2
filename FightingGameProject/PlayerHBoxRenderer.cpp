#include "PlayerHBoxRenderer.h"

#include "PlayerState.h"
#include "Loaded_HB_Data.h"

#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iTargetBoxDataController.h"
#include "iHitBoxDataController.h"

namespace RB::Render
{
    void PlayerHBoxRenderer::Init(RB::Sprites::SpriteLoader* spriteLoader)
	{
		_spriteLoader = spriteLoader;
	}
	void PlayerHBoxRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Render::iPlayerAnimationController::instance == nullptr)
		{
			return;
		}

		RenderHBox(RB::Players::PlayerID::PLAYER_1, RB::HBox::HBoxType::TARGET_BOX);
		RenderHBox(RB::Players::PlayerID::PLAYER_2, RB::HBox::HBoxType::TARGET_BOX);

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

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		iAnimationObj* aniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(playerID, spriteType);
		
		if (aniObj == nullptr)
		{
			return;
		}
		
		int currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (RB::HBox::iTargetBoxDataController::instance != nullptr)
			{
				data = RB::HBox::iTargetBoxDataController::instance->GetData(spriteType);
			}
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance != nullptr)
			{
				data = RB::HBox::iHitBoxDataController::instance->GetData(spriteType);
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

		olc::Pixel color = olc::RED;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			color = olc::MAGENTA;
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			color = olc::GREEN;
		}

		_Render(player, AABBs, color);
	}

	void PlayerHBoxRenderer::_Render(RB::Players::iPlayer* player, RB::HBox::AABB_Set* AABBs, olc::Pixel color)
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

			if (player->OtherPlayerIsOnRightSide())
			{
				olc::vf2d pos = aabb.GetBottomLeft() + player->GetPosition();

				_spriteLoader->RenderSprite(RB::Sprites::SpriteType::white_sq_tr80, aabb.GetWidthHeight(), pos, color, RB::Sprites::PivotType::BOTTOM_LEFT);
			}
			else
			{
				olc::vf2d bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				olc::vf2d pos = bottomleft + player->GetPosition();

				_spriteLoader->RenderSprite(RB::Sprites::SpriteType::white_sq_tr80, aabb.GetWidthHeight(), pos, color, RB::Sprites::PivotType::BOTTOM_RIGHT);
			}
		}
	}
}