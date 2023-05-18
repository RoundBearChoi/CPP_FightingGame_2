#include "P0_Dummy.h"

namespace RB::P0_States
{
	void P0_Dummy::OnEnter()
	{
		//change spriteEnum to edit different sprites
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnUpdate()
	{
		_getter_HurtBoxDataController.OnUpdate();

		if (_getter_HurtBoxDataController.GetController() == nullptr)
		{
			return;
		}
		
		RB::HurtBox::HurtBoxDataSet& sample = _getter_HurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::hurtbox_dataset_sample);
		RB::HurtBox::HurtBoxDataSet& idle = _getter_HurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::fighter_0_idle);

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