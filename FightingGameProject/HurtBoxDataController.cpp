#include "HurtBoxDataController.h"

namespace RB::HBox
{
	HurtBoxDataController::HurtBoxDataController(std::string dir)
	{
		_hbLoader.SetDir(dir);
	}

	void HurtBoxDataController::Init()
	{
		_hbLoader.Init();
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{
		_hbLoader.OnFixedUpdate();
	}

	Loaded_HB_Data* HurtBoxDataController::Get_L1(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hbLoader.GetL1(spriteEnum);
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hbLoader.GetPath(spriteEnum);
	}
}