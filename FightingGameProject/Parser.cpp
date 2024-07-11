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
}
