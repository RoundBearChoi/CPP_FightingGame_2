#include "HurtBoxDataController.h"

namespace RB::HBox
{
	HurtBoxDataController::HurtBoxDataController(std::string dir)
	{
		_hbLoader.SetDir(dir);
	}

	void HurtBoxDataController::Init()
	{
		_hbLoader.Init();
	}

	void HurtBoxDataController::OnUpdate()
	{
		_hbLoader.OnUpdate();
	}

	void HurtBoxDataController::OnFixedUpdate()
	{
		_hbLoader.OnFixedUpdate();
	}

	Loaded_HB_Data* HurtBoxDataController::GetData(RB::Sprites::SpriteType spriteType)
	{
		return _hbLoader.GetData(spriteType);
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteType spriteType) const
	{
		return _hbLoader.GetPath(spriteType);
	}
}