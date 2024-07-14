#include "JParser.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

namespace RB::JSON
{
	JParser::~JParser()
	{
		for (int i = 0; i < _vecLoadedRoots.size(); i++)
		{
			free(_vecLoadedRoots[i]);
		}

		_vecLoadedRoots.clear();
	}

	const json_value_s* JParser::LoadJSON(std::string path)
	{
		std::ifstream ifs(path);

		std::string str((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		//std::cout << std::endl;
		//std::cout << "loading JSON at path: " << path << std::endl;

		if (str.empty())
		{
			//std::cout << std::endl;
			//std::cout << "failed to load json.. file doesn't exist: " << path << std::endl;
		}
		else
		{
			//std::cout << loadedStr << std::endl;
		}

		str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());

		json_value_s* root = json_parse(str.c_str(), str.size());

		_vecLoadedRoots.push_back(root);

		return root;
	}

	const json_object_s* JParser::GetObj(int index)
	{
		if (_vecLoadedRoots.size() > index)
		{
			if (_vecLoadedRoots[index] != nullptr)
			{
				json_object_s* jObj = json_value_as_object(_vecLoadedRoots[index]);
				return jObj;
			}
		}

		return nullptr;
	}

	bool JParser::RootExists(int index)
	{
		if (index >= _vecLoadedRoots.size())
		{
			return false;
		}

		if (_vecLoadedRoots[index] != nullptr)
		{
			return true;
		}

		return false;
	}

	/// <summary>
	/// get element inside object
	/// </summary>
	const json_object_element_s* JParser::GetElement(const json_object_s& obj, int index)
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

	/// <summary>
	/// get element inside element
	/// </summary>
	const json_object_element_s* JParser::GetElement(const json_object_element_s& element, int index)
	{
		json_object_s* obj = json_value_as_object(element.value);

		auto subElement = GetElement(*obj, 0);

		int count = 0;

		while (subElement != nullptr)
		{
			if (count == index)
			{
				return subElement;
			}

			subElement = subElement->next;

			count++;
		}

		return nullptr;
	}

	const std::vector<const json_object_element_s*> JParser::GetAllElements(const json_object_element_s& element)
	{
		std::vector<const json_object_element_s*> vecElements;

		const json_object_element_s* e = &element;

		if (e == nullptr)
		{
			return vecElements;
		}

		while (e != nullptr)
		{
			vecElements.push_back(e);

			e = e->next;
		}

		return vecElements;
	}

	int JParser::ParseFrame(std::string str)
	{
		std::regex pattern("frame_");
		std::string replacement = "";
		std::string s = std::regex_replace(str, pattern, replacement);
		std::stringstream stream(s);
		unsigned int result;
		stream >> result;
		return result;
	}

	int JParser::GetInt_FromElement(const json_object_element_s& element)
	{
		json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		int result = 0;
		stream >> result;

		return result;
	}

	float JParser::GetFloat_FromElement(const json_object_element_s& element)
	{
		json_number_s* number = json_value_as_number(element.value);

		std::stringstream stream;
		stream << number->number;
		float result = 0.0f;
		stream >> result;

		return result;
	}

	std::string JParser::GetString_FromElement(const json_object_element_s& element)
	{
		json_string_s* string = json_value_as_string(element.value);

		std::string result = string->string;

		return result;
	}
}
