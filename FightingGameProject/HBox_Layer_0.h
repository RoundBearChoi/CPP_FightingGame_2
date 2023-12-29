#pragma once

#include "AABB.h"

#include "Selector.h"
#include "ISelector.h"

namespace RB::HBox
{
	class HBox_Layer_0
	{
	public:
		HBox_Layer_0() = default;
		HBox_Layer_0(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB);
		~HBox_Layer_0();

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