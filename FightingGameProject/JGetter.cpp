#include "JGetter.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

namespace RB::JSON
{
	std::string LoadJSONFile(std::string jsonFilePath)
	{
		//std::cout << std::endl;
		//std::cout << "loading " << jsonFilePath << ".." << std::endl;

		std::ifstream ifs(jsonFilePath);

		std::string loadedStr((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		if (loadedStr.empty())
		{
			std::cout << "file doesn't exist: " << jsonFilePath << std::endl;
		}
		else
		{
			//std::cout << loadedStr << std::endl;
		}

		loadedStr.erase(std::remove(loadedStr.begin(), loadedStr.end(), '\n'), loadedStr.cend());

		return loadedStr;
	}

	json_object_element_s* GetElementNFromObj(const json_object_s& obj, size_t index)
	{
		json_object_element_s* element = obj.start;

		size_t count = 0;

		while (element != nullptr)
		{
			if (count == index)
			{
				return element;
			}

			element = element->next;

			count++;
		}

		return nullptr;
	}

	json_object_element_s* GetElementInsideElement(const json_object_element_s& parentElement)
	{
		struct json_object_s* obj = json_value_as_object(parentElement.value);
		struct json_object_element_s* element = obj->start;

		return element;
	}

	int GetInt_FromElement(const json_object_element_s& element)
	{
		struct json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		int result = 0;
		stream >> result;

		return result;
	}

	float GetFloat_FromElement(const json_object_element_s& element)
	{
		struct json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		float result = 0.0f;
		stream >> result;

		return result;
	}

	std::string GetString_FromElement(const json_object_element_s& element)
	{
		struct json_string_s* string = json_value_as_string(element.value);

		std::string result = string->string;

		return result;
	}

	int GetInt_FromArrayElement(const json_array_element_s& element)
	{
		struct json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		int result = 0;
		stream >> result;

		return result;
	}

	float GetFloat_FromArrayElement(const json_array_element_s& element)
	{
		struct json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		float result = 0.0f;
		stream >> result;

		return result;
	}

	unsigned int ParseFrame(const std::string& str)
	{
		std::regex pattern("frame_");
		std::string replacement = "";
		std::string s = std::regex_replace(str, pattern, replacement);
		std::stringstream stream(s);
		unsigned int result;
		stream >> result;
		return result;
	}
}