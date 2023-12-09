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
			std::cout << "loading " << jsonFilePath << ".." << std::endl;

			std::ifstream ifs(jsonFilePath);

			std::string loadedStr((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
			
			if (loadedStr.empty())
			{
				std::cout << "file doesn't exist" << std::endl;
			}
			else
			{
				std::cout << loadedStr << std::endl;
			}

			loadedStr.erase(std::remove(loadedStr.begin(), loadedStr.end(), '\n'), loadedStr.cend());

			return loadedStr;
		}

		static json_object_element_s* GetElementNFromObj(const json_object_s& obj, size_t index)
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

		static json_object_element_s* GetElementInsideElement(const json_object_element_s& parentElement)
		{
			struct json_object_s* obj = json_value_as_object(parentElement.value);
			struct json_object_element_s* e0 = obj->start;

			return e0;
		}

		static int32_t GetInt32_FromElement(const json_object_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			int32_t result = 0;
			stream >> result;

			return result;
		}

		static float_t GetFloat_FromElement(const json_object_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			float_t result = 0.0f;
			stream >> result;

			return result;
		}

		static int32_t GetInt32_FromArrayElement(const json_array_element_s& element)
		{
			struct json_number_s* number = json_value_as_number(element.value);

			std::stringstream stream;
			stream << number->number;
			int32_t result = 0;
			stream >> result;

			return result;
		}

		static float_t GetFloat_FromArrayElement(const json_array_element_s& element)
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