#include "PlayerBoxSpecsLoader.h"

namespace RB::Collisions
{
	void PlayerBoxSpecsLoader::OnUpdate()
	{
		for (auto i = _vecLoadedSpecs.begin(); i != _vecLoadedSpecs.end(); i++)
		{
			i->OnUpdate();
		}
	}

	void PlayerBoxSpecsLoader::OnFixedUpdate()
	{
		for (auto i = _vecLoadedSpecs.begin(); i != _vecLoadedSpecs.end(); i++)
		{
			i->OnFixedUpdate();
		}
	}

	std::string PlayerBoxSpecsLoader::GetPath(RB::Sprites::SpriteType spriteType)
	{
		std::string spriteName = spriteType._to_string();

		return "../PlayerBoxSpecs/Aku/" + spriteName + ".playerBoxSpecs";
	}

	void PlayerBoxSpecsLoader::LoadSpecs(RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType)
	{
		std::string path = GetPath(spriteType);

		RB::JSON::JParser parser;

		parser.LoadJSON(path);

		//file doesn't exist
		if (!parser.RootExists(0))
		{
			LoadedPlayerBoxData* loaded = GetLoadedSpecs(characterType);

			if (loaded == nullptr)
			{
				_vecLoadedSpecs.push_back(LoadedPlayerBoxData(characterType));
			}
			else
			{
				loaded->Add(PlayerBoxSpecs(path, spriteType));
			}

			return;
		}

		auto jObj = parser.GetObj(0);

		json_object_element_s* element = jObj->start;

		//file exists but no data
		if (element == nullptr)
		{
			LoadedPlayerBoxData* loaded = GetLoadedSpecs(characterType);

			if (loaded == nullptr)
			{
				_vecLoadedSpecs.push_back(LoadedPlayerBoxData(characterType));
			}
			else
			{
				loaded->Add(PlayerBoxSpecs(path, spriteType));
			}

			return;
		}

		//normal file
		while (element != nullptr)
		{
			unsigned int frame = RB::JSON::JParser::ParseFrame(element->name->string);
			
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

			float offsetX = RB::JSON::JParser::GetFloat_FromElement(*e0);
			float offsetY = RB::JSON::JParser::GetFloat_FromElement(*e1);
			float width = RB::JSON::JParser::GetFloat_FromElement(*e2);
			float height = RB::JSON::JParser::GetFloat_FromElement(*e3);

			LoadedPlayerBoxData* loadedData = GetLoadedSpecs(characterType);

			//new data if not found
			if (loadedData == nullptr)
			{
				_vecLoadedSpecs.push_back(LoadedPlayerBoxData(characterType, PlayerBoxSpecs(path, spriteType, PlayerBox(frame, offsetX, offsetY, width, height))));
			}
			else
			{
				RB::Collisions::PlayerBoxSpecs* existingSpecs = loadedData->GetSpecs(spriteType);

				if (existingSpecs != nullptr)
				{
					if (existingSpecs->BoxExists(frame))
					{
						//do nothing if frame already exists
					}
					else
					{
						//only add if frame doesn't exist
						existingSpecs->GetSelector()->PushBack(PlayerBox(frame, offsetX, offsetY, width, height));
					}
				}
				else
				{
					//add new specs if data is found but no existing specs for the spriteType
					loadedData->Add(PlayerBoxSpecs(path, spriteType, PlayerBox(frame, offsetX, offsetY, width, height)));
				}
			}

			element = element->next;
		}
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

	void PlayerBoxSpecsLoader::AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType)
	{
		LoadedPlayerBoxData* loaded = GetLoadedSpecs(characterType);

		if (loaded == nullptr)
		{

		}
		else
		{
			PlayerBoxSpecs* existingSpecs = loaded->GetSpecs(spriteType);

			if (existingSpecs == nullptr)
			{
				//temp
				loaded->Add(PlayerBoxSpecs("", spriteType, box));
			}
			else
			{
				existingSpecs->AddBox(box);
			}
		}
	}
}
