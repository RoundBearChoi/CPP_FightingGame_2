#include "HurtBoxDataController.h"

namespace RB::HBox
{
	HurtBoxDataController::HurtBoxDataController(std::string dir)
	{
		_hb.PresetDir(dir);
	}

	void HurtBoxDataController::Init()
	{
		_hb.Init();
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{
		_hb.OnFixedUpdate();
	}

	HBox_Layer_1* HurtBoxDataController::Get_L1(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetL1(spriteEnum);
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hb.GetPath(spriteEnum);
	}
}