#include "HurtBoxDataController.h"

namespace RB::HBox
{
	HurtBoxDataController::HurtBoxDataController(std::string dir)
	{
		HURTBOX_DATA_CONTROLLER = this;

		_hb.PresetDir(dir);
	}

	HurtBoxDataController::~HurtBoxDataController()
	{
		HURTBOX_DATA_CONTROLLER = nullptr;
	}

	void HurtBoxDataController::Init()
	{
		_hb.Init();
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}

	HBoxDataList* HurtBoxDataController::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetDataList(spriteEnum);
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hb.GetPath(spriteEnum);
	}
}