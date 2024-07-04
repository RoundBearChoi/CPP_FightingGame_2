#include "AttackBoxDataController.h"

namespace RB::HBox
{
	AttackBoxDataController::AttackBoxDataController(std::string dir)
	{
		_hbContainer.SetDir(dir, HBoxType::ATTACK_BOX);
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

	std::string AttackBoxDataController::GetPath(RB::Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetPath(spriteType);
	}
}
