#pragma once
#include <vector>
#include <regex>
#include "SpriteEnum.h"
#include "AABB.h"

namespace RB::HurtBox
{
	class HurtBoxData
	{
	public:
		HurtBoxData() = default;

		HurtBoxData(size_t index, std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
		{
			_index = index;
			_frameName = frameName;
			_vecAABB = vecAABB;

			std::regex pattern("frame_"); 
			std::string replacement = "";
			std::string s = std::regex_replace(frameName, pattern, replacement);
			std::stringstream stream(s);
			stream >> _frame;
		}

		~HurtBoxData() = default;

	public:
		size_t GetIndex() { return _index; }
		size_t GetFrame() { return _frame; }
		size_t GetSize() { return _vecAABB.size(); }
		RB::Collisions::AABB& GetAABB(size_t index) { return _vecAABB[index]; }

	public:
		void ReserveAABBCapacity(size_t size) { _vecAABB.reserve(size); }
		void SetIndex(size_t frame) { _index = frame; }
		void SetFrameName(std::string name) { _frameName = name; }
		void AddAABB(RB::Collisions::AABB aabb) { _vecAABB.push_back(aabb); }

	private:
		size_t _index = 0;
		std::string _frameName = "";
		size_t _frame = 0;
		std::vector<RB::Collisions::AABB> _vecAABB;
	};
}