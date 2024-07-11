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
}
