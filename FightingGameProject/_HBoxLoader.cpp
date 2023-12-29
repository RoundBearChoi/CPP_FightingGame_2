#include "_HBoxLoader.h"

namespace RB::HBox
{
	void _HBoxLoader::InitSample(std::string path)
	{
		_samplePath = path;

		SaveSample();
	}

	void _HBoxLoader::SaveSample()
	{
		std::ofstream file(_samplePath);

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

	/// <summary>
	/// make sure to free root after use
	/// </summary>
	json_value_s* _HBoxLoader::LoadRoot(std::string path)
	{
		std::string loaded = RB::JSON::LoadJSONFile(path);

		const char* json = loaded.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));

		return root;
	}

	/// <summary>
	/// only use during initialization (vector addresses)
	/// </summary>
	HBox_Layer_1 _HBoxLoader::Load_L1(const std::string path, const RB::Sprites::SpriteEnum spriteEnum)
	{
		//save path - spriteEnum
		if (GetDataListPath(spriteEnum).GetSpriteEnum() == RB::Sprites::SpriteEnum::NONE)
		{
			_vecLists.push_back(HBoxDataListPath{ path, spriteEnum });
		}

		//load
		json_value_s* root = LoadRoot(path);

		if (root == nullptr)
		{
			HBox_Layer_1 defaultData{ spriteEnum };

			HBox_Layer_0 L0;
			L0.SetFrameNameAndParse("frame_0");

			defaultData.AddHBoxData(L0);

			return defaultData;
		}

		struct json_object_s* obj = json_value_as_object(root);

		HBox_Layer_1 L1{ spriteEnum };

		for (int i = 0; i < obj->length; i++)
		{
			std::vector<RB::Collisions::AABB> vec = ParseData(*obj, i);
			std::string name = ParseName(*obj, i);

			HBox_Layer_0 L0 { name, vec};
			L1.AddHBoxData(L0);
		}

		//make sure to free root after use
		free(root);

		return L1;
	}

	std::vector<RB::Collisions::AABB> _HBoxLoader::ParseData(const json_object_s& wholeObj, const unsigned int frame)
	{
		json_object_element_s* objE = wholeObj.start;

		unsigned int count = 0;
		
		while (objE != nullptr)
		{
			if (count == frame)
			{
				struct json_array_s* arr = json_value_as_array(objE->value);

				std::vector<RB::Collisions::AABB> vec;
				vec.reserve(arr->length);

				for (unsigned int i = 0; i < arr->length; i++)
				{
					RB::Collisions::AABB data = GetAABB(*arr, i);
					vec.push_back(data);
				}

				return vec;
			}

			count++;
			objE = objE->next;
		}

		return std::vector<RB::Collisions::AABB>{};
	}

	std::string _HBoxLoader::ParseName(const json_object_s& wholeObj, const unsigned int frame)
	{
		json_object_element_s* objE = wholeObj.start;

		unsigned int count = 0;

		while (objE != nullptr)
		{
			if (count == frame)
			{
				json_string_s* jstring = objE->name;

				std::string str = std::string(jstring->string, jstring->string_size);

				return str;
			}

			count++;
			objE = objE->next;
		}

		return "";
	}

	RB::Collisions::AABB _HBoxLoader::GetAABB(const json_array_s& jArray, unsigned int index)
	{
		unsigned int count = 0;

		json_array_element_s* element = jArray.start;

		while (element != nullptr)
		{
			if (count == index)
			{
				json_object_s* obj = json_value_as_object(element->value);

				json_object_element_s* posX_Element = RB::JSON::GetElementNFromObj(*obj, 0);
				json_object_element_s* posY_Element = RB::JSON::GetElementNFromObj(*obj, 1);
				json_object_element_s* width_Element = RB::JSON::GetElementNFromObj(*obj, 2);
				json_object_element_s* height_Element = RB::JSON::GetElementNFromObj(*obj, 3);

				float x = RB::JSON::GetFloat_FromElement(*posX_Element);
				float y = RB::JSON::GetFloat_FromElement(*posY_Element);
				float width = RB::JSON::GetFloat_FromElement(*width_Element);
				float height = RB::JSON::GetFloat_FromElement(*height_Element);

				RB::Collisions::AABB aabb{ x, y, width, height };

				return aabb;
			}

			element = element->next;

			count++;
		}

		return RB::Collisions::AABB();
	}

	const RB::HBox::HBoxDataListPath& _HBoxLoader::GetDataListPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		const std::vector<HBoxDataListPath>& vec = _getVector();

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if ((*i).GetSpriteEnum() == spriteEnum)
			{
				return (*i);
			}
		}

		return _none;
	}
}