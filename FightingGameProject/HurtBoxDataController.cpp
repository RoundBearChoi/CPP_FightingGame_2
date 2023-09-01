#include "HurtBoxDataController.h"

namespace RB::HBox
{
	HurtBoxDataController::HurtBoxDataController()
	{
		HURTBOX_DATA_CONTROLLER = this;
	}

	HurtBoxDataController::~HurtBoxDataController()
	{
		HURTBOX_DATA_CONTROLLER = nullptr;
	}

	void HurtBoxDataController::Init()
	{
		SetHash(typeid(*this));

		_hb.Init();

		////temp
		//_loader.InitSample("HurtBoxSpecs/Sample.HurtBoxSpecs");
		//
		////temp - load every hurtbox datalist
		//_vecLists.push_back(_loader.LoadDataList("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteEnum::hurtbox_datalist_sample));
		//_vecLists.push_back(_loader.LoadDataList("HurtBoxSpecs/fighter_0_idle.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_idle));
		//_vecLists.push_back(_loader.LoadDataList("HurtBoxSpecs/fighter_0_walk.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_walk));
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

		//for (size_t i = 0; i < _vecLists.size(); i++)
		//{
		//	if (_vecLists[i].GetSpriteEnum() == spriteEnum)
		//	{
		//		return &_vecLists[i];
		//	}
		//}
		//
		//return nullptr;
	}

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _hb.GetPath(spriteEnum);

		//HBoxDataListPath* p = _loader.GetDataListPath(spriteEnum);
		//
		//if (p != nullptr)
		//{
		//	return p->GetPath();
		//}
		//
		//return _none;
	}
}