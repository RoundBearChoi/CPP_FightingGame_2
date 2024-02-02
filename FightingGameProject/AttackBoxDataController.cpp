#include "AttackBoxDataController.h"

namespace RB::HBox
{
	AttackBoxDataController::AttackBoxDataController(std::string dir)
	{
		_hbLoader.SetDir(dir);
	}

	void AttackBoxDataController::Init()
	{
		_hbLoader.Init();
	}

	void AttackBoxDataController::OnUpdate()
	{
		_hbLoader.OnUpdate();
	}

	void AttackBoxDataController::OnFixedUpdate()
	{
		_hbLoader.OnFixedUpdate();
	}

	Loaded_HB_Data* AttackBoxDataController::GetData(RB::Sprites::SpriteType spriteType)
	{
		return _hbLoader.GetData(spriteType);
	}

	const std::string& AttackBoxDataController::GetPath(RB::Sprites::SpriteType spriteType) const
	{
		return _hbLoader.GetPath(spriteType);
	}
}