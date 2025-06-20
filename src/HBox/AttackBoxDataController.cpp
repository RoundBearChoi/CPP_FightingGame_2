#include "AttackBoxDataController.h"

namespace RB::HBox
{
	AttackBoxDataController::AttackBoxDataController(std::string dir)
	{
		_hbContainer.SetDir(dir, HBoxType::ATTACK_BOX);
	}

	void AttackBoxDataController::Init()
	{
		//INIT_CONTROLLER
		
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

	Loaded_HB_Data* AttackBoxDataController::CreateData(RB::Sprites::SpriteType spriteType)
	{
		return _hbContainer.CreateData(spriteType);
	}

	std::string AttackBoxDataController::GetPath(RB::Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetPath(spriteType);
	}
}
