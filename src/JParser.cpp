#include "JParser.h"

#include <iostream>
#include <regex>
#include <sstream>
#include <algorithm>

#include "Logger/iLogController.h"

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
		auto logController = GET_LOG_CONTROLLER;
		std::stringstream ss;
		ss << "path " << path;

        std::ifstream ifs(path);

        std::string str((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

        if (str.empty())
        {
			ss << " ===> FAILED! can't find json";
			logController->AddToStream(Players::PlayerID::NONE, Log::LOG_TYPE::LOAD_JSON, ss.str()); 
			return nullptr;
        }

        str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());

        json_value_s* root = json_parse(str.c_str(), str.size());

        if (root == nullptr)
        {
			ss << " ===> FAILED! can't parse json"; 
			logController->AddToStream(Players::PlayerID::NONE, Log::LOG_TYPE::LOAD_JSON, ss.str()); 
			return nullptr;
        }

        _vecLoadedRoots.push_back(root);

		logController->AddToStream(Players::PlayerID::NONE, Log::LOG_TYPE::LOAD_JSON, ss.str()); 
        
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
