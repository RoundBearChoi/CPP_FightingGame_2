#include "TargetBoxDataController.h"

namespace RB::HBox
{
	TargetBoxDataController::TargetBoxDataController(std::string dir)
	{
		_hbContainer.SetDir(dir, HBoxType::TARGET_BOX);
	}

	void TargetBoxDataController::Init()
	{
		_hbContainer.Init();
	}

	void TargetBoxDataController::OnUpdate()
	{
		_hbContainer.OnUpdate();
	}

	void TargetBoxDataController::OnFixedUpdate()
	{
		_hbContainer.OnFixedUpdate();
	}

	Loaded_HB_Data* TargetBoxDataController::GetData(RB::Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetData(spriteType);
	}

	std::string TargetBoxDataController::GetPath(RB::Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetPath(spriteType);
	}
}
