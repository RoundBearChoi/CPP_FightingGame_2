#include "JGetter.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#include "Parser.h"

namespace RB::JSON
{
	int GetInt_FromElement(const json_object_element_s& element)
	{
		json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		int result = 0;
		stream >> result;

		return result;
	}

	float GetFloat_FromElement(const json_object_element_s& element)
	{
		json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		float result = 0.0f;
		stream >> result;

		return result;
	}

	std::string GetString_FromElement(const json_object_element_s& element)
	{
		json_string_s* string = json_value_as_string(element.value);

		std::string result = string->string;

		return result;
	}

	/// <summary>
	/// assuming there's 1 root element and a bunch of elements inside that
	/// </summary>
	//std::vector<json_object_element_s*> GetAllElements(json_object_s* jObj)
	//{
	//	json_object_element_s* rootElement = RB::JSON::Parser::GetElement(*jObj, 0);
	//
	//	std::vector<json_object_element_s*> vecElements;
	//
	//	if (rootElement == nullptr)
	//	{
	//		return vecElements;
	//	}
	//
	//	json_object_element_s* e = RB::JSON::Parser::GetElement(*rootElement, 0);
	//
	//	while (e != nullptr)
	//	{
	//		vecElements.push_back(e);
	//		e = e->next;
	//	}
	//
	//	return vecElements;
	//}

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
