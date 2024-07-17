#pragma once

#include <vector>
#include <string>

#include "json.h"

namespace RB::JSON
{
	class JParser
	{
	public:
		~JParser();

	public:
		const json_value_s* LoadJSON(std::string path);
		const json_object_s* GetObj(int index);
		bool RootExists(int index);

	public:
		static const json_object_element_s* GetElement(const json_object_s& obj, int index);
		static const json_object_element_s* GetElement(const json_object_element_s& element, int index);
		static const std::vector<const json_object_element_s*> GetAllElements(const json_object_element_s& element);
		static int ParseFrame(std::string str);
		static int GetInt_FromElement(const json_object_element_s& element);
		static float GetFloat_FromElement(const json_object_element_s& element);
		static std::string GetString_FromElement(const json_object_element_s& element);

	private:
		std::vector<json_value_s*> _vecLoadedRoots;
	};
}
