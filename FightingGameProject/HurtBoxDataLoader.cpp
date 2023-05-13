#include "HurtBoxDataLoader.h"

namespace RB::HurtBox
{
	void HurtBoxDataLoader::Init()
	{
		SaveSample();
		LoadSample();

		SaveSample2();
		LoadSample2();
	}

	void HurtBoxDataLoader::LoadSample()
	{
		std::string loaded = RB::JSON::JGetter::LoadJSONFile("HurtBoxData/Sample.HurtBoxData");
		const char* json = loaded.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));
		struct json_object_s* object = json_value_as_object(root);

		HurtBoxData data = GetHurtBoxData(*object, 2);

		free(root);
	}

	void HurtBoxDataLoader::SaveSample()
	{
		std::string path = "HurtBoxData/Sample.HurtBoxData";

		std::ofstream file(path);

		if (file.is_open())
		{
			file << "{" << std::endl;
			file << "\"sets count\" : 4," << std::endl;

			file << "\"position\" : [1, 2]," << std::endl;
			file << "\"size\" : [1.1, 2.2]," << std::endl;

			file << "\"position\" : [3, 4]," << std::endl;
			file << "\"size\" : [3.3, 4.4]," << std::endl;

			file << "\"position\" : [5, 6]," << std::endl;
			file << "\"size\" : [5.5, 6.6]," << std::endl;

			file << "\"position\" : [7, 8]," << std::endl;
			file << "\"size\" : [7.7, 8.8]" << std::endl;
			file << "}" << std::endl;

			file.flush();
			file.close();
		}
	}

	void HurtBoxDataLoader::LoadSample2()
	{
		std::string loaded = RB::JSON::JGetter::LoadJSONFile("HurtBoxData/Sample2.HurtBoxData");
		const char* json = loaded.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));
		struct json_array_s* jArray = json_value_as_array(root);

		free(root);
	}

	void HurtBoxDataLoader::SaveSample2()
	{
		std::string path = "HurtBoxData/Sample2.HurtBoxData";

		std::ofstream file(path);

		if (file.is_open())
		{
			file << "[" << std::endl;
			file << "{" << std::endl;
			file << "\"posX\" : 1," << std::endl;
			file << "\"posY\" : 2," << std::endl;
			file << "\"width\" : 1.1," << std::endl;
			file << "\"height\" : 2.2" << std::endl;
			file << "}" << std::endl;
			file << "]" << std::endl;

			file.flush();
			file.close();
		}
	}

	HurtBoxData HurtBoxDataLoader::GetHurtBoxData(const json_object_s& object, int setIndex)
	{
		json_object_element_s* countElement = RB::JSON::JGetter::GetFirstElement(object, "sets count");
		int totalSetsCount = RB::JSON::JGetter::GetInt_FromElement(*countElement);

		if (setIndex >= totalSetsCount)
		{
			return HurtBoxData();
		}

		json_object_element_s* positionElement = RB::JSON::JGetter::GetElementN(object, setIndex * 2 + 1);
		json_object_element_s* sizeElement = RB::JSON::JGetter::GetElementN(object, setIndex * 2 + 2);

		struct json_array_s* arrPos = json_value_as_array(positionElement->value);

		struct json_array_element_s* posX_Element = RB::JSON::JGetter::GetFirstArrayElement(*arrPos);
		struct json_array_element_s* posY_Element = RB::JSON::JGetter::GetNextArrayElement(*posX_Element);

		int posX = RB::JSON::JGetter::GetInt_FromArrayElement(*posX_Element);
		int posY = RB::JSON::JGetter::GetInt_FromArrayElement(*posY_Element);

		struct json_array_s* arrSize = json_value_as_array(sizeElement->value);

		struct json_array_element_s* width_Element = RB::JSON::JGetter::GetFirstArrayElement(*arrSize);
		struct json_array_element_s* height_Element = RB::JSON::JGetter::GetNextArrayElement(*width_Element);

		float width = RB::JSON::JGetter::GetFloat_FromArrayAelement(*width_Element);
		float height = RB::JSON::JGetter::GetFloat_FromArrayAelement(*height_Element);

		HurtBoxData data{ posX, posY, width, height };

		return data;
	}
}