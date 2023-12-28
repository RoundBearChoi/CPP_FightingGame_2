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
		RB::iSelector<RB::Collisions::AABB>* GetSelector();

	public:
		unsigned int GetFrame();
		const std::string& GetFrameName();
		void SetFrameNameAndParse(const std::string& name);

	private:
		unsigned int _ParseFrame(const std::string& str);

	private:
		std::string _frameName = "";
		unsigned int _frame = 0;
		bool _selectionInitialized = false;
		RB::Selector<RB::Collisions::AABB> _selector;
	};
}