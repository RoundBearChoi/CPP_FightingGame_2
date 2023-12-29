#include "HitBoxDataController.h"

namespace RB::HBox
{
	HitBoxDataController::HitBoxDataController(std::string dir)
	{
		_L2.SetDir(dir);
	}

	void HitBoxDataController::Init()
	{
		_L2.Init();
	}

	void HitBoxDataController::OnUpdate()
	{

	}

	void HitBoxDataController::OnFixedUpdate()
	{
		_L2.OnFixedUpdate();
	}

	HBox_Layer_1* HitBoxDataController::Get_L1(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _L2.GetL1(spriteEnum);
	}

	const std::string& HitBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _L2.GetPath(spriteEnum);
	}
}