#pragma once
#include <vector>
#include <regex>
#include "SpriteEnum.h"
#include "AABB.h"

namespace RB::HBox
{
	class HBoxData
	{
	public:
		HBoxData() = default;
		HBoxData(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB);
		~HBoxData() = default;

	public:
		size_t GetFrame();
		unsigned int GetAABBCount();
		RB::Collisions::AABB& GetAABB(size_t index);
		const std::string& GetFrameName();

	public:
		void ReserveAABBCapacity(size_t size);
		void SetFrameNameAndParse(const std::string& name);
		void AddAABB(RB::Collisions::AABB aabb);
		bool DeleteAABB(size_t index);

	private:
		size_t _ParseFrame(const std::string& str);

	private:
		std::string _frameName = "";
		size_t _frame = 0;
		std::vector<RB::Collisions::AABB> _vecAABB;
	};
}