#include "HitBoxDataController.h"

namespace RB::HBox
{
	HitBoxDataController::HitBoxDataController(std::string dir)
	{
		HITBOX_DATA_CONTROLLER = this;

		_hb.PresetDir(dir);
	}

	HitBoxDataController::~HitBoxDataController()
	{
		HITBOX_DATA_CONTROLLER = nullptr;
	}

	void HitBoxDataController::Init()
	{
		SetHash(typeid(*this));

		_hb.Init();
	}

	void HitBoxDataController::OnUpdate()
	{

	}

	void HitBoxDataController::OnFixedUpdate()
	{

	}

	HBoxDataList* HitBoxDataController::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetDataList(spriteEnum);
	}

	const std::string& HitBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		return _hb.GetPath(spriteEnum);
	}
}