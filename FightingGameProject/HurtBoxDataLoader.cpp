#include "HurtBoxDataLoader.h"

namespace RB::HurtBox
{
	void HurtBoxSpecsLoader::Init()
	{
		SaveSample();

		json_value_s* root = LoadRoot("HurtBoxSpecs/Sample.HurtBoxSpecs");

		struct json_object_s* obj = json_value_as_object(root);
		size_t length = obj->length;

		std::vector<HurtBoxData> vecData;
		vecData.reserve(length);
		
		for (size_t i = 0; i < length; i++)
		{
			std::vector<HurtBoxSpecs> vec = ParseData(*obj, i);
		
			HurtBoxData data{ i, vec };
		
			vecData.push_back(data);
		}

		free(root);
	}

	json_value_s* HurtBoxSpecsLoader::LoadRoot(std::string path)
	{
		std::string loaded = RB::JSON::JGetter::LoadJSONFile(path);

		const char* json = loaded.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));

		return root;
	}

	std::vector<HurtBoxSpecs> HurtBoxSpecsLoader::ParseData(const json_object_s& wholeObj, size_t frame)
	{
		json_object_element_s* objE = wholeObj.start;

		int count = 0;
		
		while (objE != nullptr)
		{
			if (count == frame)
			{
				struct json_array_s* arr = json_value_as_array(objE->value);

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
			objE = objE->next;
		}

		return std::vector<HurtBoxSpecs>{};
	}

	void HurtBoxSpecsLoader::SaveSample()
	{
		std::string path = "HurtBoxSpecs/Sample.HurtBoxSpecs";

		std::ofstream file(path);

		if (file.is_open())
		{
			//start of whole obj
			file << "{" << std::endl;

			file << "    \"frame_0\":" << std::endl;
			file << "    [" << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 1," << std::endl;
			file << "        \"posY\" : 2," << std::endl;
			file << "        \"width\" : 1.1," << std::endl;
			file << "        \"height\" : 2.2" << std::endl;
			file << "        }," << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 3," << std::endl;
			file << "        \"posY\" : 4," << std::endl;
			file << "        \"width\" : 3.3," << std::endl;
			file << "        \"height\" : 4.4" << std::endl;
			file << "        }," << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 5," << std::endl;
			file << "        \"posY\" : 6," << std::endl;
			file << "        \"width\" : 5.5," << std::endl;
			file << "        \"height\" : 6.6" << std::endl;
			file << "        }," << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 7," << std::endl;
			file << "        \"posY\" : 8," << std::endl;
			file << "        \"width\" : 7.7," << std::endl;
			file << "        \"height\" : 8.8" << std::endl;
			file << "        }" << std::endl;

			file << "    ]," << std::endl;
			file << std::endl;

			file << "    \"frame_1\":" << std::endl;
			file << "    [" << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 1," << std::endl;
			file << "        \"posY\" : 2," << std::endl;
			file << "        \"width\" : 1.5," << std::endl;
			file << "        \"height\" : 2.5" << std::endl;
			file << "        }" << std::endl;
			
			file << "    ]," << std::endl;
			file << std::endl;

			file << "    \"frame_2\":" << std::endl;
			file << "    [" << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 10," << std::endl;
			file << "        \"posY\" : 20," << std::endl;
			file << "        \"width\" : 1.111," << std::endl;
			file << "        \"height\" : 2.222" << std::endl;
			file << "        }," << std::endl;

			file << "        {" << std::endl;
			file << "        \"posX\" : 30," << std::endl;
			file << "        \"posY\" : 40," << std::endl;
			file << "        \"width\" : 3.333," << std::endl;
			file << "        \"height\" : 4.444" << std::endl;
			file << "        }" << std::endl;

			file << "    ]" << std::endl;

			//end of whole obj
			file << "}"; 

			file.flush();
			file.close();
		}
	}

	HurtBoxSpecs HurtBoxSpecsLoader::GetHurtBoxSpecs(const json_array_s& jArray, size_t index)
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