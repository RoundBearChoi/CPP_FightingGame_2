#include "TargetBoxDataController.h"

namespace RB::HBox
{
	TargetBoxDataController::TargetBoxDataController()
	{
		std::string specsPath = "../resource/TargetBoxSpecs/";
		_hbContainer.SetDir(specsPath, HBoxType::TARGET_BOX);
	}

	void TargetBoxDataController::Init()
	{
		//INIT_CONTROLLER
		
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

	Loaded_HB_Data* TargetBoxDataController::GetData(Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetData(spriteType);
	}

	Loaded_HB_Data* TargetBoxDataController::CreateData(Sprites::SpriteType spriteType)
	{
		return _hbContainer.CreateData(spriteType);
	}

	std::string TargetBoxDataController::GetPath(Sprites::SpriteType spriteType)
	{
		return _hbContainer.GetPath(spriteType);
	}
}
