#include "HitBoxDataController.h"

namespace RB::HBox
{
	HitBoxDataController::HitBoxDataController(std::string dir)
	{
		_hb.PresetDir(dir);
	}

	void HitBoxDataController::Init()
	{
		_hb.Init();
	}

	void HitBoxDataController::OnUpdate()
	{

	}

	void HitBoxDataController::OnFixedUpdate()
	{
		_hb.OnFixedUpdate();
	}

	HBox_Layer_1* HitBoxDataController::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetL1(spriteEnum);
	}

	const std::string& HitBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hb.GetPath(spriteEnum);
	}
}