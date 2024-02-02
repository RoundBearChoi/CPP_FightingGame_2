#include "TargetBoxDataController.h"

namespace RB::HBox
{
	TargetBoxDataController::TargetBoxDataController(std::string dir)
	{
		_hbLoader.SetDir(dir);
	}

	void TargetBoxDataController::Init()
	{
		_hbLoader.Init();
	}

	void TargetBoxDataController::OnUpdate()
	{
		_hbLoader.OnUpdate();
	}

	void TargetBoxDataController::OnFixedUpdate()
	{
		_hbLoader.OnFixedUpdate();
	}

	Loaded_HB_Data* TargetBoxDataController::GetData(RB::Sprites::SpriteType spriteType)
	{
		return _hbLoader.GetData(spriteType);
	}

	const std::string& TargetBoxDataController::GetPath(RB::Sprites::SpriteType spriteType) const
	{
		return _hbLoader.GetPath(spriteType);
	}
}