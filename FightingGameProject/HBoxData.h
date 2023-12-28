#pragma once
#include <vector>
#include <regex>
#include "SpriteEnum.h"
#include "AABB.h"
#include "Selector.h"

namespace RB::HBox
{
	class HBoxData
	{
	public:
		HBoxData() = default;
		HBoxData(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB);
		~HBoxData();

	public:
		void Init();
		void OnFixedUpdate();

	public:
		unsigned int GetFrame();
		const std::vector<RB::Collisions::AABB>& GetVecAABBs();
		RB::Collisions::AABB* GetSelectedAABB();
		void UpSelection();
		void DownSelection();
		RB::Collisions::AABB& GetAABB(unsigned int index);
		const std::string& GetFrameName();

	public:
		void SetFrameNameAndParse(const std::string& name);
		void AddAABB(RB::Collisions::AABB aabb);
		bool DeleteAABB(unsigned int index);
		void DeleteSelectedAABB();
		RB::Selector<RB::Collisions::AABB>* GetSelector();

	private:
		unsigned int _ParseFrame(const std::string& str);

	private:
		std::string _frameName = "";
		unsigned int _frame = 0;
		std::vector<RB::Collisions::AABB> _vecAABB;
		bool _selectionInitialized = false;
		std::vector<RB::Collisions::AABB>::iterator _selected;
		RB::Selector<RB::Collisions::AABB>* _selector = nullptr;
	};
}