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

	HBoxDataList* HitBoxDataController::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetDataList(spriteEnum);
	}

	const std::string& HitBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hb.GetPath(spriteEnum);
	}
}