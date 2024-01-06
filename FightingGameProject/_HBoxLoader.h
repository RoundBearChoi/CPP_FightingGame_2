#pragma once
#include <vector>
#include "json.h"

#include "Loaded_HB_Data.h"
#include "HBoxDataListPath.h"

namespace RB::HBox
{
	class _HBoxLoader
	{
	public:
		_HBoxLoader() = default;
		~_HBoxLoader() = default;

	public:
		void InitSample(std::string path);
		void SaveSample();

	public:
		Loaded_HB_Data Load(const std::string path, const RB::Sprites::SpriteType spriteType);
		std::vector<RB::Collisions::AABB> ParseData(const json_object_s& wholeObj, const unsigned int frame);
		std::string ParseName(const json_object_s& wholeObj, const unsigned int frame);

	public:
		RB::Collisions::AABB GetAABB(const json_array_s& array, unsigned int index);
		const RB::HBox::HBoxDataListPath& GetDataListPath(RB::Sprites::SpriteType spriteType) const;
		

	private:
		std::vector<HBoxDataListPath> _vecLists;
		const std::vector<HBoxDataListPath>& _getVector() const { return _vecLists; }
		std::string _samplePath;

		const HBoxDataListPath _none = { "none", RB::Sprites::SpriteType::NONE };
	};
}