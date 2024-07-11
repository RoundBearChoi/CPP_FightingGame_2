#pragma once

#include <string>
#include <vector>

#include "json.h"

namespace RB::JSON
{
	extern int GetInt_FromElement(const json_object_element_s& element);
	extern float GetFloat_FromElement(const json_object_element_s& element);
	extern std::string GetString_FromElement(const json_object_element_s& element);
	extern std::vector<json_object_element_s*> GetAllElements(json_object_s* jObj);

	extern unsigned int ParseFrame(const std::string& str);
}
