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

		struct json_array_s* arrPos = json_value_as_array(positionElement->value);
		
		struct json_array_element_s* posX_Element = RB::JSON::JGetter::GetFirstArrayElement(*arrPos);
		struct json_array_element_s* posY_Element = RB::JSON::JGetter::GetNextArrayElement(*posX_Element);

		int posX = RB::JSON::JGetter::GetArrayElementInt(*posX_Element);
		int posY = RB::JSON::JGetter::GetArrayElementInt(*posY_Element);

		struct json_array_s* arrSize = json_value_as_array(sizeElement->value);

		struct json_array_element_s* width_Element = RB::JSON::JGetter::GetFirstArrayElement(*arrSize);
		struct json_array_element_s* height_Element = RB::JSON::JGetter::GetNextArrayElement(*width_Element);

		float width = RB::JSON::JGetter::GetArrayElementFloat(*width_Element);
		float height = RB::JSON::JGetter::GetArrayElementFloat(*height_Element);

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