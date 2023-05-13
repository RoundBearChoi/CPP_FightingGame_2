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
	};
}