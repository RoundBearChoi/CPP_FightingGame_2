#pragma once

#include <string>

#include "json.h"

namespace RB::JSON
{
	std::string LoadJSONFile(std::string jsonFilePath);
	json_object_element_s* GetElementNFromObj(const json_object_s& obj, size_t index);
	json_object_element_s* GetElementInsideElement(const json_object_element_s& parentElement);
	int GetInt_FromElement(const json_object_element_s& element);
	float GetFloat_FromElement(const json_object_element_s& element);
	std::string GetString_FromElement(const json_object_element_s& element);
	//int GetInt_FromArrayElement(const json_array_element_s& element);
	//float GetFloat_FromArrayElement(const json_array_element_s& element);

	unsigned int ParseFrame(const std::string& str);
}