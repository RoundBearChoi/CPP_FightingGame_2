#include "PlayerHurtBoxRenderer.h"

namespace RB::Render
{
    void PlayerHurtBoxRenderer::Init(SpriteRenderer* spriteRenderer)
	{
		_spriteRenderer = spriteRenderer;
	}
	void PlayerHurtBoxRenderer::OnUpdate()
	{
		_getter_playerController.OnUpdate();
		_getter_playerAnimationController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr ||
			_getter_playerAnimationController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr)
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
		//RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);
		//
		//if (player == nullptr)
		//{
		//	return;
		//}

		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		//PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);
		//
		//if (aniObj == nullptr)
		//{
		//	return;
		//}
		//
		//int32_t currentIndex = aniObj->GetCurrentIndex();

		RB::HurtBox::HurtBoxDataSet dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);
	}
}