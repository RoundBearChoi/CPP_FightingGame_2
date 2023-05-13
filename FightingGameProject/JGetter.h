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

		static int GetInt_FromElement(const json_object_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			int result = 0;
			stream >> result;

			return result;
		}

		static float GetFloat_FromElement(const json_object_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			float result = 0.0f;
			stream >> result;

			return result;
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

		static float GetFloat_FromArrayElement(const json_array_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			float result = 0.0f;
			stream >> result;

			return result;
		}
	};
}