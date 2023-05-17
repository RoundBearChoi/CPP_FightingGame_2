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

		HurtBoxData(size_t frame, std::vector<RB::Collisions::AABB> vecAABB)
		{
			_frame = frame;
			_vecAABB = vecAABB;
		}

		~HurtBoxData() = default;

	public:
		size_t GetFrame() { return _frame; }
		void SetFrame(size_t frame) { _frame = frame; }
		void AddAABB(RB::Collisions::AABB aabb) { _vecAABB.push_back(aabb); }
		void SetSpecs(std::vector<RB::Collisions::AABB> vec) { _vecAABB = vec; }
		const RB::Collisions::AABB& GetSpecs(size_t index) { return _vecAABB[index]; }

	private:
		size_t _frame = 0;
		std::vector<RB::Collisions::AABB> _vecAABB;
	};
}