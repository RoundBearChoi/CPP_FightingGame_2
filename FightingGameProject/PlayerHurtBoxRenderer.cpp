#include "PlayerHurtBoxRenderer.h"

namespace RB::Render
{
    void PlayerHurtBoxRenderer::Init(SpriteRenderer* spriteRenderer)
	{
		_spriteRenderer = spriteRenderer;
	}
	void PlayerHurtBoxRenderer::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Render::PLAYER_ANIMATION_CONTROLLER == nullptr ||
			RB::HBox::HURTBOX_DATA_CONTROLLER == nullptr)
		{
			return;
		}

		RenderHBox(RB::Players::PlayerID::PLAYER_1, RB::HBox::HBoxType::HURT_BOX);
		RenderHBox(RB::Players::PlayerID::PLAYER_2, RB::HBox::HBoxType::HURT_BOX);
	}

	void PlayerHurtBoxRenderer::OnFixedUpdate()
	{

	}

	void PlayerHurtBoxRenderer::RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType)
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(playerID);
		
		if (player == nullptr)
		{
			return;
		}

		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		iPlayerAnimationObj* aniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(playerID, spriteEnum);
		
		if (aniObj == nullptr)
		{
			return;
		}
		
		int32_t currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::HBoxDataList* dataList = nullptr;

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{

		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{

		}

		dataList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(spriteEnum);

		if (dataList == nullptr)
		{
			return;
		}

		RB::HBox::HBoxData* data = dataList->GetHBoxDataByFrame(currentIndex);

		size_t count = data->GetAABBCount();

		if (count == 0)
		{
			int n = 0;
		}

		for (size_t i = 0; i < count; i++)
		{
			RB::Collisions::AABB& aabb = data->GetAABB(i);

			if (aabb.GetWidthHeight().x <= 0.001f)
			{
				continue;
			}
			
			if (aabb.GetWidthHeight().y <= 0.001f)
			{
				continue;
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

			if (player->OtherPlayerIsOnRightSide())
			{
				olc::vf2d pos = aabb.GetBottomLeft() + player->GetPosition();
				_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, color, RB::Sprites::PivotType::BOTTOM_LEFT);
			}
			else
			{
				olc::vf2d bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				olc::vf2d pos = bottomleft + player->GetPosition();
				_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, color, RB::Sprites::PivotType::BOTTOM_RIGHT);
			}
		}
	}
}