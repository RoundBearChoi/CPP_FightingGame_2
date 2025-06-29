#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "json.h"

namespace RB::JSON
{
    class JParser
    {
    public:
        ~JParser();

    public:
        const json_value_s* LoadJSON(std::string path);
        const json_object_s* GetObj(int index);
        bool RootExists(int index);

        const json_object_element_s* GetElement(const json_object_s& obj, int index);
        const json_object_element_s* GetElement(const json_object_element_s& element, int index);
        const std::vector<const json_object_element_s*> GetAllElements(const json_object_element_s& element);
        int ParseFrame(std::string str);
        int GetInt_FromElement(const json_object_element_s& element);
        float GetFloat_FromElement(const json_object_element_s& element);
        std::string GetString_FromElement(const json_object_element_s& element);

    private:
        std::vector<json_value_s*> _vecLoadedRoots;
    };
}
