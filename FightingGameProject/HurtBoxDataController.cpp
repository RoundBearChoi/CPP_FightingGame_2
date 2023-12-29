#include "HurtBoxDataController.h"

namespace RB::HBox
{
	HurtBoxDataController::HurtBoxDataController(std::string dir)
	{
		_L2.SetDir(dir);
	}

	void HurtBoxDataController::Init()
	{
		_L2.Init();
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{
		_L2.OnFixedUpdate();
	}

	HBox_Layer_1* HurtBoxDataController::Get_L1(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _L2.GetL1(spriteEnum);
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _L2.GetPath(spriteEnum);
	}
}