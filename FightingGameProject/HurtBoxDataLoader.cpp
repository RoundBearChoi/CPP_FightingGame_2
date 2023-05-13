#include "HurtBoxDataLoader.h"
#include "JGetter.h"

namespace RB::HurtBox
{
	void HurtBoxDataLoader::Init()
	{
		SaveSample();
		LoadSample();
	}

	void HurtBoxDataLoader::LoadSample()
	{
		std::cout << std::endl;
		std::cout << "loading sample HurtBoxData.." << std::endl;

		std::ifstream ifs("HurtBoxData/Sample.HurtBoxData");

		std::string loadedStr((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		loadedStr.erase(std::remove(loadedStr.begin(), loadedStr.end(), '\n'), loadedStr.cend());

		std::cout << loadedStr << std::endl;

		const char* json = loadedStr.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));
		struct json_object_s* object = json_value_as_object(root);

		json_object_element_s* positionElement = RB::JSON::JGetter::GetFirstElement(*object, "position");
		json_object_element_s* sizeElement = RB::JSON::JGetter::GetNextElement(*positionElement, "size");

		//struct json_object_element_s* posElement = object->start;
		//struct json_string_s* posName = posElement->name;

		//struct json_array_s* posArray = json_value_as_array(posElement->value);
		//struct json_array_element_s* xElement = posArray->start;
		//struct json_array_element_s* yElement = xElement->next;
		//struct json_number_s* xNumber = json_value_as_number(xElement->value);
		//struct json_number_s* yNumber = json_value_as_number(yElement->value);
		//
		//std::stringstream xStringStream;
		//std::stringstream yStringStream;
		//
		//xStringStream << xNumber->number;
		//yStringStream << yNumber->number;
		//
		//int x;
		//int y;
		//
		//xStringStream >> x;
		//yStringStream >> y;

		free(root);
	}

	void HurtBoxDataLoader::SaveSample()
	{
		std::string path = "HurtBoxData/";

		path += "Sample.HurtBoxData";

		std::ofstream file(path);

		if (file.is_open())
		{
			file << "{" << std::endl;
			file << "\"position\" : [5, 6]," << std::endl;
			file << "\"size\" : [123, 3.14]" << std::endl;
			file << "}" << std::endl;

			file.flush();
			file.close();
		}
	}
}