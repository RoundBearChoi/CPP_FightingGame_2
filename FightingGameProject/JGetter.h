#pragma once

#include <string>
#include <vector>

#include "json.h"

namespace RB::JSON
{
	extern int GetInt_FromElement(const json_object_element_s& element);
	extern float GetFloat_FromElement(const json_object_element_s& element);
	extern std::string GetString_FromElement(const json_object_element_s& element);

	extern unsigned int ParseFrame(const std::string& str);
}
