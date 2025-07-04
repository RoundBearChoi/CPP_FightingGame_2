#include "AttackBoxDataController.h"

namespace RB::HBox
{
	AttackBoxDataController::AttackBoxDataController()
	{
		std::string specsPath = "../resource/AttackBoxSpecs/";
		_hbContainer.SetDir(specsPath, HBoxType::ATTACK_BOX);
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

	Loaded_HB_Data* AttackBoxDataController::GetData(Sprites::SPRITE_TYPE spriteType)
	{
		return _hbContainer.GetData(spriteType);
	}

	Loaded_HB_Data* AttackBoxDataController::CreateData(Sprites::SPRITE_TYPE spriteType)
	{
		return _hbContainer.CreateData(spriteType);
	}

	std::string AttackBoxDataController::GetPath(Sprites::SPRITE_TYPE spriteType)
	{
		return _hbContainer.GetPath(spriteType);
	}
}
