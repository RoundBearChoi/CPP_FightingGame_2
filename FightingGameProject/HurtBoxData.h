#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HurtBoxSpecs.h"

namespace RB::HurtBox
{
	class HurtBoxData
	{
	public:
		HurtBoxData() = default;

		HurtBoxData(size_t frame, std::vector<HurtBoxSpecs> vecSpecs)
		{
			_frame = frame;
			_vecSpecs = vecSpecs;
		}

		~HurtBoxData() = default;

	public:
		size_t GetFrame() { return _frame; }
		void SetFrame(size_t frame) { _frame = frame; }
		void AddSpecs(HurtBoxSpecs specs) { _vecSpecs.push_back(specs); }
		void SetSpecs(std::vector<HurtBoxSpecs> vecSpecs) { _vecSpecs = vecSpecs; }
		const HurtBoxSpecs& GetSpecs(size_t index) { return _vecSpecs[index]; }

	private:
		size_t _frame = 0;
		std::vector<HurtBoxSpecs> _vecSpecs;
	};
}