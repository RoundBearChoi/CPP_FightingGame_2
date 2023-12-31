#include "PlayerBoxSpecsLoader.h"

#include "JGetter.h"
#include "PlayerBoxSpecs.h"

namespace RB::Collisions
{
	void PlayerBoxSpecsLoader::LoadSpecs(std::string path, RB::Sprites::SpriteEnum spriteType, RB::Players::CharacterType characterType)
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
		
			PlayerBox newBox;
			newBox.mFrame = frame;
			newBox.mOffsetX = offsetX;
			newBox.mOffsetY = offsetY;
			newBox.mWidth = width;
			newBox.mHeight = height;

			PlayerBoxSpecs newSpecs;
			newSpecs.SetSpriteType(spriteType);
			newSpecs.GetSelector()->PushBack(newBox);

			LoadedPlayerBoxData* loadedData = GetLoadedSpecs(characterType);

			//new data if not found
			if (loadedData == nullptr)
			{
				LoadedPlayerBoxData newData;
				newData.SetCharacterType(characterType);

				newData.Add(newSpecs);

				_vecLoadedSpecs.push_back(newData);
			}
			else
			{
				RB::Collisions::PlayerBoxSpecs* existingSpecs = loadedData->GetSpecs(spriteType);

				if (existingSpecs != nullptr)
				{
					if (existingSpecs->BoxExists(frame, newBox))
					{
						//do nothing if frame already exists
					}
					else
					{
						//only add if frame doesn't exist
						existingSpecs->GetSelector()->PushBack(newBox);
					}
				}
				else
				{
					//add new specs if data is found but no existing spriteType specs
					loadedData->Add(newSpecs);
				}
			}

			element = element->next;
		}

		free(root);
	}

	LoadedPlayerBoxData* PlayerBoxSpecsLoader::GetLoadedSpecs(RB::Players::CharacterType characterType)
	{
		for (auto i = _vecLoadedSpecs.begin(); i != _vecLoadedSpecs.end(); i++)
		{
			if (i->GetCharacterType() == characterType)
			{
				return &(*i);
			}
		}

		return nullptr;
	}
}