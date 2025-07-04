#include "PlayerBoxSpecs.h"

namespace RB::Collisions
{
	PlayerBoxSpecs::PlayerBoxSpecs(std::string path, Sprites::SPRITE_TYPE spriteType)
	{
		_path = path;
		_spriteType = spriteType;
	}

	PlayerBoxSpecs::PlayerBoxSpecs(std::string path, Sprites::SPRITE_TYPE spriteType, PlayerBox box)
	{
		_path = path;
		_spriteType = spriteType;

		_selector.PushBack(box);
	}

	void PlayerBoxSpecs::OnUpdate()
	{
		_notification.OnUpdate("File saved: " + _path);
		_selector.OnUpdate();
	}

	void PlayerBoxSpecs::OnFixedUpdate()
	{
		_notification.OnFixedUpdate();
		_selector.OnFixedUpdate();
	}

	void PlayerBoxSpecs::AddBox(PlayerBox box)
	{
		GetSelector()->PushBack(box);
	}

	Sprites::SPRITE_TYPE PlayerBoxSpecs::GetSpriteType()
	{
		return _spriteType;
	}

	iSelector<PlayerBox>* PlayerBoxSpecs::GetSelector()
	{
		return &_selector;
	}

	bool PlayerBoxSpecs::BoxExists(unsigned int frame)
	{
		const auto& vec = _selector.GetVector();

		auto it = vec.begin();

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if (i->mFrame == frame)
			{
				return true;
			}
		}

		return false;
	}

	const Collisions::PlayerBox& PlayerBoxSpecs::GetBox(unsigned int frame)
	{
		const auto& vec = _selector.GetVector();

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if (i->mFrame == frame)
			{
				return *i;
			}
		}

		return _emptyBox;
	}

	Collisions::PlayerBox* PlayerBoxSpecs::GetBox_ptr(unsigned int frame)
	{
		auto* vec = _selector.GetVector_ptr();

		for (auto i = vec->begin(); i != vec->end(); i++)
		{
			if (i->mFrame == frame)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	void PlayerBoxSpecs::Save()
	{
		if (_path.empty())
		{
			std::cout << std::endl;
			std::cout << "missing path for spriteType: " << _spriteType._to_string() << std::endl;
			std::cout << "can't save data. make sure data is loaded first" << std::endl;

			return;
		}

		auto* vec = _selector.GetVector_ptr();

		std::stringstream ss;
		
		ss << "{" << std::endl;

		for (auto i = vec->begin(); i != vec->end(); i++)
		{
			ss << "    \"frame_" << i->mFrame << "\":" << std::endl;
			ss << "    [" << std::endl;
			ss << "        {" << std::endl;
			ss << "        \"offsetX\" : " << i->mOffsetX << "," << std::endl;
			ss << "        \"offsetY\" : " << i->mOffsetY << "," << std::endl;
			ss << "        \"width\" : " << i->mWidth << "," << std::endl;
			ss << "        \"height\" : " << i->mHeight << std::endl;
			ss << "        }" << std::endl;

			if (i != vec->end() - 1)
			{
				ss << "    ]," << std::endl << std::endl;
			}
			else
			{
				ss << "    ]" << std::endl;
			}
		}

		ss << "}";

		_writer.WriteToLogFile(_path, ss.str(), true);

		_notification.AddFrameCount(120);
	}
}
