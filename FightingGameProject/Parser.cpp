#include "Parser.h"

#include <iostream>
#include <fstream>

namespace RB::JSON
{
	Parser::~Parser()
	{
		for (int i = 0; i < _vecLoadedRoots.size(); i++)
		{
			free(_vecLoadedRoots[i]);
		}

		_vecLoadedRoots.clear();
	}

	json_value_s* Parser::LoadJSON(std::string path)
	{
		std::ifstream ifs(path);

		std::string str((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		//std::cout << std::endl;
		//std::cout << "loading JSON at path: " << path << std::endl;

		if (str.empty())
		{
			std::cout << std::endl;
			std::cout << "failed to load json.. file doesn't exist: " << path << std::endl;
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

	json_object_s* Parser::GetObj(int index)
	{
		if (_vecLoadedRoots.size() > index)
		{
			json_object_s* jObj = json_value_as_object(_vecLoadedRoots[index]);
			return jObj;
		}

		return nullptr;
	}

	bool Parser::RootExists(int index)
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
	json_object_element_s* Parser::GetElement(const json_object_s& obj, int index)
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
	json_object_element_s* Parser::GetElement(const json_object_element_s& element, int index)
	{
		json_object_s* obj = json_value_as_object(element.value);

		json_object_element_s* subElement = GetElement(*obj, 0);

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

	std::vector<json_object_element_s*> Parser::GetAllElements(const json_object_s& jObj)
	{
		json_object_element_s* rootElement = RB::JSON::Parser::GetElement(jObj, 0);

		std::vector<json_object_element_s*> vecElements;

		if (rootElement == nullptr)
		{
			return vecElements;
		}

		json_object_element_s* e = RB::JSON::Parser::GetElement(*rootElement, 0);

		while (e != nullptr)
		{
			vecElements.push_back(e);
			e = e->next;
		}

		return vecElements;
	}

	std::vector<const json_object_element_s*> Parser::GetAllElements_FIXED(const json_object_element_s& element)
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
}
