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
		_hbLoader.OnUpdate();
	}

	void HitBoxDataController::OnFixedUpdate()
	{
		_hbLoader.OnFixedUpdate();
	}

	Loaded_HB_Data* HitBoxDataController::GetData(RB::Sprites::SpriteType spriteType)
	{
		return _hbLoader.GetData(spriteType);
	}

	const std::string& HitBoxDataController::GetPath(RB::Sprites::SpriteType spriteType) const
	{
		return _hbLoader.GetPath(spriteType);
	}
}