#pragma once
#include <iostream>
#include "json.h"

namespace RB::JSON
{
	class JGetter
	{
	public:
		JGetter() = delete;
		~JGetter() = delete;

	public:
		static std::string LoadJSONFile(std::string jsonFilePath)
		{
			std::cout << std::endl;
			std::cout << "loading json: " << jsonFilePath << std::endl;

			std::ifstream ifs(jsonFilePath);

			std::string loadedStr((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

			std::cout << std::endl;
			std::cout << loadedStr << std::endl;

			loadedStr.erase(std::remove(loadedStr.begin(), loadedStr.end(), '\n'), loadedStr.cend());

			//std::cout << std::endl;
			//std::cout << loadedStr << std::endl;

			return loadedStr;
		}

		static json_object_element_s* GetFirstElement(const json_object_s& obj, std::string name)
		{
			json_object_element_s* firstElement = obj.start;
			struct json_string_s* elementName = firstElement->name;

			const char* nameChar = name.c_str();

			if (strcmp(elementName->string, nameChar) == 0)
			{
				return firstElement;
			}

			return nullptr;
		}

		static json_object_element_s* GetElementN(const json_object_s& obj, int index)
		{
			json_object_element_s* element = obj.start;

			int count = 0;
			
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

		static json_object_element_s* GetNextElement(const json_object_element_s& element, std::string name)
		{
			json_object_element_s* nextElement = element.next;
			struct json_string_s* elementName = nextElement->name;

			const char* nameChar = name.c_str();

			if (strcmp(elementName->string, nameChar) == 0)
			{
				return nextElement;
			}

			return nullptr;
		}

		static int GetInt_FromElement(const json_object_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			int result = 0;
			stream >> result;

			return result;
		}

		static json_array_element_s* GetFirstArrayElement(const json_array_s& arr)
		{
			json_array_element_s* firstElement = arr.start;

			return firstElement;
		}

		static int GetInt_FromArrayElement(const json_array_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			int result = 0;
			stream >> result;

			return result;
		}

		static float GetFloat_FromArrayAelement(const json_array_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			float result = 0.0f;
			stream >> result;

			return result;
		}

		static json_array_element_s* GetNextArrayElement(const json_array_element_s& element)
		{
			json_array_element_s* nextElement = element.next;

			return nextElement;
		}
	};
}