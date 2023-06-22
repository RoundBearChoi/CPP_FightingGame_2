#include "PlayerHurtBoxRenderer.h"

namespace RB::Render
{
    void PlayerHurtBoxRenderer::Init(SpriteRenderer* spriteRenderer)
	{
		_spriteRenderer = spriteRenderer;
	}
	void PlayerHurtBoxRenderer::OnUpdate()
	{
		//_getter_playerController.OnUpdate();
		_getter_playerAnimationController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();

		if (//_getter_playerController.GetController() == nullptr ||
			_getter_playerAnimationController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr)
		{
			return;
		}

		if (RB::Players::PlayerController::PTR == nullptr)
		{
			return;
		}

		RenderHurtBox(RB::Players::PlayerID::PLAYER_1);
		RenderHurtBox(RB::Players::PlayerID::PLAYER_2);
	}

	void PlayerHurtBoxRenderer::OnFixedUpdate()
	{

	}

	void PlayerHurtBoxRenderer::RenderHurtBox(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = RB::Players::PlayerController::PTR->GetPlayerOnID(playerID); //_getter_playerController.GetController()->GetPlayerOnID(playerID);
		
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

		PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);
		
		if (aniObj == nullptr)
		{
			return;
		}
		
		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HBox::HBoxDataSet* dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);

		if (dataSet == nullptr)
		{
			return;
		}

		RB::HBox::HBoxData* data = dataSet->GetHBoxDataByFrame(currentIndex);

		size_t count = data->GetAABBCount();

		for (size_t i = 0; i < count; i++)
		{
			RB::Collisions::AABB& aabb = data->GetAABB(i);

			if (player->OtherPlayerIsOnRightSide())
			{
				olc::vf2d pos = aabb.GetBottomLeft() + player->GetPosition();
				_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, olc::MAGENTA, RB::Sprites::PivotType::BOTTOM_LEFT);
			}
			else
			{
				olc::vf2d bottomleft = aabb.GetBottomLeft();
				bottomleft.x *= -1.0f;
				olc::vf2d pos = bottomleft + player->GetPosition();
				_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, olc::MAGENTA, RB::Sprites::PivotType::BOTTOM_RIGHT);
			}
		}
	}
}