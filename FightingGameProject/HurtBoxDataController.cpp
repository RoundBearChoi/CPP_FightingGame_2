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

	HBox_Layer_1* HurtBoxDataController::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetDataList(spriteEnum);
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hb.GetPath(spriteEnum);
	}
}