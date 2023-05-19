#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "AABB.h"

namespace RB::HurtBox
{
	class HurtBoxData
	{
	public:
		HurtBoxData() = default;

		HurtBoxData(size_t index, std::vector<RB::Collisions::AABB> vecAABB)
		{
			_index = index;
			_vecAABB = vecAABB;
		}

		~HurtBoxData() = default;

	public:
		size_t GetIndex() { return _index; }
		void SetIndex(size_t frame) { _index = frame; }
		void AddAABB(RB::Collisions::AABB aabb) { _vecAABB.push_back(aabb); }
		void SetSpecs(std::vector<RB::Collisions::AABB> vec) { _vecAABB = vec; }
		RB::Collisions::AABB& GetSpecs(size_t index) { return _vecAABB[index]; }

	private:
		size_t _index = 0;
		std::vector<RB::Collisions::AABB> _vecAABB;
	};
}