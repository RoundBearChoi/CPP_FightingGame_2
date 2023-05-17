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
		if (_hurtBoxDataController == nullptr)
		{
			_hurtBoxDataController = RB::Controllers::ActiveControllers::GetController<RB::HurtBox::HurtBoxDataController>();

			return;
		}
		
		RB::HurtBox::HurtBoxDataSet dataSet = _hurtBoxDataController->GetDataSet(RB::Sprites::SpriteEnum::hurtbox_dataset_sample);

		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}