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
			
			//json_object_s* obj = json_value_as_object(element->value);
			//
			//json_object_element_s* e0 = RB::JSON::GetElementNFromObj(*obj, 0);
		
			element = element->next;
		}

		free(root);
	}
}