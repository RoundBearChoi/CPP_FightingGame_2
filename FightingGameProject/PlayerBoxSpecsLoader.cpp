#include "PlayerBoxSpecsLoader.h"

#include "JGetter.h"

namespace RB::Collisions
{
	void PlayerBoxSpecsLoader::LoadSpecs(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		std::string loaded = RB::JSON::LoadJSONFile(path);

		json_value_s* root = json_parse(loaded.c_str(), loaded.length());

		json_object_s* jObj = json_value_as_object(root);

		json_object_element_s* element = jObj->start;
		
		while (element != nullptr)
		{
			unsigned int frame = RB::JSON::ParseFrame(element->name->string);
			
			json_array_s* arr = json_value_as_array(element->value);

			if (arr == nullptr)
			{
				element = element->next;
				continue;
			}

			json_array_element_s* arrayElement = arr->start;

			if (arrayElement == nullptr)
			{
				element = element->next;
				continue;
			}

			json_object_s* obj0 = json_value_as_object(arrayElement->value);
			json_object_element_s* e0 = obj0->start;
			json_object_element_s* e1 = e0->next;
			json_object_element_s* e2 = e1->next;
			json_object_element_s* e3 = e2->next;

			float offsetX = RB::JSON::GetFloat_FromElement(*e0);
			float offsetY = RB::JSON::GetFloat_FromElement(*e1);
			float width = RB::JSON::GetFloat_FromElement(*e2);
			float height = RB::JSON::GetFloat_FromElement(*e3);
		
			PlayerBoxSpecs specs;
			specs.mFrame = frame;
			specs.mOffsetX = offsetX;
			specs.mOffsetY = offsetY;
			specs.mWidth = width;
			specs.mHeight = height;
			specs.mSpriteType = spriteEnum;

			_vecSpecs.push_back(specs);

			element = element->next;
		}

		free(root);
	}
}