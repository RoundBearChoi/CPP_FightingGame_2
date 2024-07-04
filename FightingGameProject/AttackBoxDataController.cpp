#include "AttackBoxDataController.h"

namespace RB::HBox
{
	AttackBoxDataController::AttackBoxDataController(std::string dir)
	{
		_hbContainer.SetDir(dir);
	}

	void AttackBoxDataController::Init()
	{
		_hbContainer.Init();
	}

	void AttackBoxDataController::OnUpdate()
	{
		_hbContainer.OnUpdate();
	}

	void AttackBoxDataController::OnFixedUpdate()
	{
		_hbContainer.OnFixedUpdate();
	}

	Loaded_HB_Data* AttackBoxDataController::GetData(RB::Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetData(spriteType);
	}

	const std::string& AttackBoxDataController::GetPath(RB::Sprites::SpriteType spriteType) const
	{
		return _hbContainer.GetPath(spriteType);
	}
}
