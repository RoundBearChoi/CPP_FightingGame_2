#include "P0_Dummy.h"

namespace RB::P0_States
{
	void P0_Dummy::OnEnter()
	{
		_finder_HurtBoxDataController.Init();

		//change spriteEnum to edit different sprites
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnUpdate()
	{
		_finder_HurtBoxDataController.OnUpdate();

		if (_finder_HurtBoxDataController.GetController() == nullptr)
		{
			return;
		}
		
		RB::HurtBox::HurtBoxDataSet& sample = _finder_HurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::hurtbox_dataset_sample);
		RB::HurtBox::HurtBoxDataSet& idle = _finder_HurtBoxDataController.GetController()->GetDataSet(RB::Sprites::SpriteEnum::fighter_0_idle);

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