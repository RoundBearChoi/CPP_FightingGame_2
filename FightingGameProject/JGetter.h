#pragma once

#include <string>
#include <vector>

#include "json.h"

namespace RB::JSON
{
	std::string LoadJSONFile(std::string jsonFilePath);
	json_object_element_s* GetElementNFromObj(const json_object_s& obj, size_t index);
	json_object_element_s* GetElementInsideElement(const json_object_element_s& parentElement);
	int GetInt_FromElement(const json_object_element_s& element);
	float GetFloat_FromElement(const json_object_element_s& element);
	std::string GetString_FromElement(const json_object_element_s& element);
	std::vector<json_object_element_s*> GetAllElements(json_object_s* jObj);

	unsigned int ParseFrame(const std::string& str);
}
