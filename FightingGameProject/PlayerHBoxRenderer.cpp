#include "PlayerHBoxRenderer.h"

#include "Vector2.h"

#include "PlayerState.h"
#include "Loaded_HB_Data.h"

#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iTargetBoxDataController.h"
#include "iAttackBoxDataController.h"

namespace RB::Render
{
    void PlayerHBoxRenderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}
	void PlayerHBoxRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Render::iPlayerAnimationController::Get() == nullptr)
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
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(playerID);
		
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

		iAnimationObj* aniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(playerID, spriteType);
		
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

		olc::Pixel color = olc::RED;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			color = olc::MAGENTA;
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
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

			if (player->IsFacingRight())
			{
				RB::Vector2 pos = aabb.GetBottomLeft() + player->GetPosition();

				_spriteContainer->RenderSprite(RB::Sprites::SpriteType::white_sq_tr80, aabb.GetWidthHeight().x, aabb.GetWidthHeight().y, pos, color, RB::Sprites::PivotType::BOTTOM_LEFT, true);
			}
			else
			{
				RB::Vector2 bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				RB::Vector2 pos = bottomleft + player->GetPosition();

				_spriteContainer->RenderSprite(RB::Sprites::SpriteType::white_sq_tr80, aabb.GetWidthHeight().x, aabb.GetWidthHeight().y, pos, color, RB::Sprites::PivotType::BOTTOM_RIGHT, true);
			}
		}
	}
}
