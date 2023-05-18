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

		RB::HurtBox::HurtBoxDataSet& sample = _getter_hurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::hurtbox_dataset_sample);
		RB::HurtBox::HurtBoxDataSet& idle = _getter_hurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::fighter_0_idle);

		RB::HurtBox::HurtBoxData& id = idle.GetHurtBoxData(0);

		RB::HurtBox::HurtBoxData& s0 = sample.GetHurtBoxData(0);
		RB::HurtBox::HurtBoxData& s1 = sample.GetHurtBoxData(1);

		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}