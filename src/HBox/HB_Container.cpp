#include "HB_Container.h"

#include "../Logger/iLogController.h"

namespace RB::HBox
{
	void HB_Container::Init()
	{
		auto logController = GET_LOG_CONTROLLER;

		logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_JSON, "loading fighter 0 hboxes");

		//load every hbox datalist
		for (int i = Sprites::SPRITE_TYPE::FIGHTER_0_SPRITES_START + 1; i < Sprites::SPRITE_TYPE::FIGHTER_0_SPRITES_END; i++)
		{
			_vecData.push_back(_loader.Load(CreatePath(Sprites::SPRITE_TYPE::_from_index(i)), Sprites::SPRITE_TYPE::_from_index((i)), _boxType));
		}
	}

	void HB_Container::OnFixedUpdate()
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void HB_Container::OnUpdate()
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			(*i).OnUpdate();
		}
	}

	void HB_Container::SetDir(std::string dir, HBoxType boxType)
	{
		_dir = dir;
		_boxType = boxType;
	}

	Loaded_HB_Data* HB_Container::GetData(Sprites::SPRITE_TYPE spriteType)
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			if ((*i).GetSpriteType() == spriteType)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	Loaded_HB_Data* HB_Container::CreateData(Sprites::SPRITE_TYPE spriteType)
	{
		Loaded_HB_Data* existing = GetData(spriteType);

		if (existing == nullptr)
		{
			Loaded_HB_Data newData{ spriteType, _boxType };

			_vecData.push_back(newData);

			return &_vecData[_vecData.size() - 1];
		}

		return existing;
	}

	std::string HB_Container::CreatePath(Sprites::SPRITE_TYPE spriteType)
	{
		std::string str = spriteType._to_string();
		return _dir + str + _extention;
	}

	std::string HB_Container::GetPath(Sprites::SPRITE_TYPE spriteType)
	{
		std::string spr = spriteType._to_string();
		std::string path = _dir + spr;
		path += _extention;

		return path;
	}
}
