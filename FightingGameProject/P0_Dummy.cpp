#include "P0_Dummy.h"

namespace RB::PlayerStates
{
	void P0_Dummy::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		//change spriteEnum to edit different sprites
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnExit()
	{
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Dummy::OnUpdate()
	{
		_getter_playerController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr || _getter_hurtBoxDataController.GetController() == nullptr)
		{
			return;
		}
		
		_ownerPlayer = _getter_playerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);

		//RB::HurtBox::HurtBoxDataSet* sample = _getter_hurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::hurtbox_dataset_sample);
		//RB::HurtBox::HurtBoxDataSet* idle = _getter_hurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::fighter_0_idle);
		//
		//RB::HurtBox::HurtBoxData* idle0 = idle->GetHurtBoxDataByIndex(0);
		//RB::HurtBox::HurtBoxData* idle1 = idle->GetHurtBoxDataByIndex(1);
		//
		//RB::HurtBox::HurtBoxData* s0 = sample->GetHurtBoxDataByIndex(0);
		//RB::HurtBox::HurtBoxData* s1 = sample->GetHurtBoxDataByIndex(1);
		//RB::HurtBox::HurtBoxData* s2 = sample->GetHurtBoxDataByIndex(2);
		//RB::HurtBox::HurtBoxData* s3 = sample->GetHurtBoxDataByIndex(3);

		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}