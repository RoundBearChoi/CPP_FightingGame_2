#include "HurtBoxDataLoader.h"

namespace RB::HurtBox
{
	void HurtBoxDataLoader::Init()
	{
		SaveSample();
		LoadSample();

		json_value_s* root = LoadRoot("HurtBoxData/Sample.HurtBoxData");
		json_array_s* arr = json_value_as_array(root);
		size_t length = arr->length;

		std::vector<HurtBoxDataSet> vecSets;
		vecSets.reserve(length);

		for (size_t i = 0; i < length; i++)
		{
			std::vector<HurtBoxSpecs> vec = ParseData(root, i);

			HurtBoxDataSet set{ RB::Sprites::SpriteID::NONE, vec, i };

			vecSets.push_back(set);
		}

		free(root);
	}

	json_value_s* HurtBoxDataLoader::LoadRoot(std::string path)
	{
		std::string loaded = RB::JSON::JGetter::LoadJSONFile(path);

		const char* json = loaded.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));

		return root;
	}

	std::vector<HurtBoxSpecs> HurtBoxDataLoader::ParseData(json_value_s* root, size_t frame)
	{
		struct json_array_s* whole = json_value_as_array(root);
		json_array_element_s* element = whole->start;

		int count = 0;
		
		while (element != nullptr)
		{
			if (count == frame)
			{
				struct json_array_s* arr = json_value_as_array(element->value);

				std::vector<HurtBoxSpecs> vec;
				vec.reserve(arr->length);

				for (size_t i = 0; i < arr->length; i++)
				{
					HurtBoxSpecs data = GetHurtBoxSpecs(*arr, i);
					vec.push_back(data);
				}

				return vec;
			}

			count++;
			element = element->next;
		}

		return std::vector<HurtBoxSpecs>{};
	}

	void HurtBoxDataLoader::LoadSample()
	{
		std::string loaded = RB::JSON::JGetter::LoadJSONFile("HurtBoxData/Sample.HurtBoxData");
		const char* json = loaded.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));

		struct json_array_s* whole = json_value_as_array(root);

		//struct json_array_s* arr = json_value_as_array(whole->start->value);
		struct json_array_s* arr = json_value_as_array(whole->start->next->value);

		size_t count = arr->length;

		std::vector<HurtBoxSpecs> vec;
		
		for (size_t i = 0; i < count; i++)
		{
			HurtBoxSpecs data = GetHurtBoxSpecs(*arr, i);
		
			vec.push_back(data);
		}
		
		free(root);
	}

	void HurtBoxDataLoader::SaveSample()
	{
		std::string path = "HurtBoxData/Sample.HurtBoxData";

		std::ofstream file(path);

		if (file.is_open())
		{
			//start of whole array
			file << "[" << std::endl;

			//frame 0
			file << "[" << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 1," << std::endl;
			file << "\"posY\" : 2," << std::endl;
			file << "\"width\" : 1.1," << std::endl;
			file << "\"height\" : 2.2" << std::endl;
			file << "}," << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 3," << std::endl;
			file << "\"posY\" : 4," << std::endl;
			file << "\"width\" : 3.3," << std::endl;
			file << "\"height\" : 4.4" << std::endl;
			file << "}," << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 5," << std::endl;
			file << "\"posY\" : 6," << std::endl;
			file << "\"width\" : 5.5," << std::endl;
			file << "\"height\" : 6.6" << std::endl;
			file << "}," << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 7," << std::endl;
			file << "\"posY\" : 8," << std::endl;
			file << "\"width\" : 7.7," << std::endl;
			file << "\"height\" : 8.8" << std::endl;
			file << "}" << std::endl;

			file << "]," << std::endl;

			//frame 1
			file << "[" << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 1," << std::endl;
			file << "\"posY\" : 2," << std::endl;
			file << "\"width\" : 1.5," << std::endl;
			file << "\"height\" : 2.5" << std::endl;
			file << "}" << std::endl;
			
			file << "]," << std::endl;

			//frame 2
			file << "[" << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 10," << std::endl;
			file << "\"posY\" : 20," << std::endl;
			file << "\"width\" : 1.111," << std::endl;
			file << "\"height\" : 2.222" << std::endl;
			file << "}," << std::endl;

			file << "{" << std::endl;
			file << "\"posX\" : 30," << std::endl;
			file << "\"posY\" : 40," << std::endl;
			file << "\"width\" : 3.333," << std::endl;
			file << "\"height\" : 4.444" << std::endl;
			file << "}" << std::endl;

			file << "]" << std::endl;

			//end of whole array
			file << "]"; 

			file.flush();
			file.close();
		}
	}

	HurtBoxSpecs HurtBoxDataLoader::GetHurtBoxSpecs(const json_array_s& jArray, size_t index)
	{
		int count = 0;

		json_array_element_s* element = jArray.start;

		while (element != nullptr)
		{
			if (count == index)
			{
				json_object_s* obj = json_value_as_object(element->value);

				json_object_element_s* posX_Element = RB::JSON::JGetter::GetElementN(*obj, 0);
				json_object_element_s* posY_Element = RB::JSON::JGetter::GetElementN(*obj, 1);
				json_object_element_s* width_Element = RB::JSON::JGetter::GetElementN(*obj, 2);
				json_object_element_s* height_Element = RB::JSON::JGetter::GetElementN(*obj, 3);

				int x = RB::JSON::JGetter::GetInt_FromElement(*posX_Element);
				int y = RB::JSON::JGetter::GetInt_FromElement(*posY_Element);
				float width = RB::JSON::JGetter::GetFloat_FromElement(*width_Element);
				float height = RB::JSON::JGetter::GetFloat_FromElement(*height_Element);

				HurtBoxSpecs data{ x, y, width, height };

				return data;
			}

			element = element->next;

			count++;
		}

		return HurtBoxSpecs();
	}
}