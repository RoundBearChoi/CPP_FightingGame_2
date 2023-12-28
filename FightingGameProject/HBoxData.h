#pragma once
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
		void OnFixedUpdate();

	public:
		unsigned int GetFrame();
		RB::Collisions::AABB* GetSelectedAABB();
		void UpSelection();
		void DownSelection();
		const std::string& GetFrameName();

	public:
		void SetFrameNameAndParse(const std::string& name);
		void DeleteSelectedAABB();
		RB::iSelector<RB::Collisions::AABB>* GetSelector();

	private:
		unsigned int _ParseFrame(const std::string& str);

	private:
		std::string _frameName = "";
		unsigned int _frame = 0;
		bool _selectionInitialized = false;
		RB::Selector<RB::Collisions::AABB> _selector;
	};
}