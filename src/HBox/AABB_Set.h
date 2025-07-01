#pragma once

#include "../Collisions/AABB.h"
#include "../JParser.h"
#include "../Selector.h"

#include "../iSelector.h"

namespace RB::HBox
{
	class AABB_Set
	{
	public:
		AABB_Set() = default;
		AABB_Set(std::string frameName);
		AABB_Set(std::string frameName, std::vector<Collisions::AABB> vecAABB);
		~AABB_Set();

	public:
		void OnFixedUpdate();
		void OnUpdate();
		RB::iSelector<Collisions::AABB>* GetSelector();

	public:
		unsigned int GetFrame();
		const std::string& GetFrameName();
		void SetFrameNameAndParse(const std::string& name);

	private:
		std::string _frameName = "";
		unsigned int _frame = 0;
		bool _selectionInitialized = false;
		RB::Selector<Collisions::AABB> _selector;
	};
}
