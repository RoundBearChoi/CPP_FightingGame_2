#include "PlayerBoxSpecsLoader.h"

#include "JGetter.h"

namespace RB::Collisions
{
	void PlayerBoxSpecsLoader::LoadSpecs(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		std::string loaded = RB::JSON::LoadJSONFile(path);

		json_value_s* root = json_parse(loaded.c_str(), loaded.length());

		json_object_s* jObj = json_value_as_object(root);

		json_object_element_s* element = RB::JSON::GetElementNFromObj(*jObj, 0);

		while (element != nullptr)
		{
			element = element->next;
		}

		free(root);
	}
}