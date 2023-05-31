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
		HurtBoxData(size_t index, std::string frameName, std::vector<RB::Collisions::AABB> vecAABB);
		~HurtBoxData() = default;

	public:
		size_t GetIndex();
		size_t GetFrame();
		size_t GetAABBCount();
		RB::Collisions::AABB& GetAABB(size_t index);

	public:
		void ReserveAABBCapacity(size_t size);
		void SetIndex(size_t frame);
		void SetFrameName(const std::string& name);
		void AddAABB(RB::Collisions::AABB aabb);

	private:
		size_t _ParseFrame(const std::string& str);

	private:
		size_t _index = 0;
		std::string _frameName = "";
		size_t _frame = 0;
		std::vector<RB::Collisions::AABB> _vecAABB;
	};
}