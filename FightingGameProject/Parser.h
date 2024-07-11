#pragma once

#include <vector>
#include <string>

#include "json.h"

namespace RB::JSON
{
	class Parser
	{
	public:
		~Parser();

	public:
		json_value_s* LoadJSON(std::string path);
		json_object_s* GetObj(int index);
		bool RootExists(int index);

	public:
		static json_object_element_s* GetElement(const json_object_s& obj, int index);
		static json_object_element_s* GetElement(const json_object_element_s& element, int index);
		//static std::vector<json_object_element_s*> GetAllElements(const json_object_s& jObj);
		static std::vector<const json_object_element_s*> GetAllElements_FIXED(const json_object_element_s& element);

	private:
		std::vector<json_value_s*> _vecLoadedRoots;
	};
}
