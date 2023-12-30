#include "HitBoxDataController.h"

namespace RB::HBox
{
	HitBoxDataController::HitBoxDataController(std::string dir)
	{
		_hbLoader.SetDir(dir);
	}

	void HitBoxDataController::Init()
	{
		_hbLoader.Init();
	}

	void HitBoxDataController::OnUpdate()
	{

	}

	void HitBoxDataController::OnFixedUpdate()
	{
		_hbLoader.OnFixedUpdate();
	}

	Loaded_HB_Data* HitBoxDataController::GetData(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hbLoader.GetData(spriteEnum);
	}

	const std::string& HitBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hbLoader.GetPath(spriteEnum);
	}
}