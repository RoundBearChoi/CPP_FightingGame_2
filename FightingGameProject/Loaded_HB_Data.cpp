#include "Loaded_HB_Data.h"

namespace RB::HBox
{
	Loaded_HB_Data::Loaded_HB_Data(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;
	}

	void Loaded_HB_Data::OnFixedUpdate()
	{
		for (auto i = _vec_AABB_Sets.begin(); i != _vec_AABB_Sets.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void Loaded_HB_Data::OnUpdate()
	{
		for (auto i = _vec_AABB_Sets.begin(); i != _vec_AABB_Sets.end(); i++)
		{
			(*i).OnUpdate();
		}
	}

	void Loaded_HB_Data::AddSet(AABB_Set data)
	{
		_vec_AABB_Sets.push_back(data);
	}

	const std::vector<AABB_Set>& Loaded_HB_Data::Get_AABB_Sets()
	{
		return _vec_AABB_Sets;
	}

	AABB_Set* Loaded_HB_Data::GetHBoxDataByFrame(unsigned int frame)
	{
		//failsafe
		if (_vec_AABB_Sets.empty())
		{
			return nullptr;
		}

		//exising data
		for (auto i = _vec_AABB_Sets.begin(); i != _vec_AABB_Sets.end(); i++)
		{
			if ((*i).GetFrame() == frame)
			{
				return &(*i);
			}
		}

		//default data if no existing data
		AABB_Set s;
		s.SetFrameNameAndParse("frame_" + std::to_string(frame));

		_vec_AABB_Sets.push_back(s);

		//make sure to refresh iterators after making changes to the vector
		for (auto i = _vec_AABB_Sets.begin(); i != _vec_AABB_Sets.end(); i++)
		{
			(*i).GetSelector()->SetRefreshed(false);
		}

		return &(*(_vec_AABB_Sets.end() - 1));
	}

	RB::Sprites::SpriteEnum Loaded_HB_Data::GetSpriteEnum()
	{
		return _spriteEnum;
	}
}