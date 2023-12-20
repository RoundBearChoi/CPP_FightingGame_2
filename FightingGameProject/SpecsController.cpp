#include "SpecsController.h"

namespace RB::Players::Specs
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
		//MoveSpecs testSpecs;
		//testSpecs.mCharacterType = RB::Players::CharacterType::PLAYER_0;
		//testSpecs.mJumpUp_totalFrames = 15;
		//testSpecs.mJumpUp_speedMultiplier = 28.0f;

		//_SaveMoveSpecs("MoveSpecs/Aku_moveSpecs.moveSpecs", testSpecs);

		_LoadMoveSpecs("MoveSpecs/Aku_moveSpecs.moveSpecs");
	}

	void SpecsController::OnUpdate()
	{

	}

	void SpecsController::OnFixedUpdate()
	{

	}

	MoveSpecs SpecsController::GetMoveSpecs(RB::Players::CharacterType characterType)
	{
		for (size_t i = 0; i < _vecMoveSpecs.size(); i++)
		{
			if (_vecMoveSpecs[i].mCharacterType == characterType)
			{
				return _vecMoveSpecs[i];
			}
		}

		std::cout << "no specs found" << std::endl;

		return MoveSpecs(characterType);
	}

	void SpecsController::_SaveMoveSpecs(std::string path, MoveSpecs specs)
	{
		std::ofstream file(path);

		std::string name = "Aku move specs";

		if (file.is_open())
		{
			//start
			file << "{" << std::endl;

			//start of parent element
			file << "    \"" << name << "\":" << std::endl;

			file << "        {" << std::endl;
			file << "        \"mCharacterType\" : " << RB::Players::GetString(specs.mCharacterType) << "," << std::endl;
			file << "        \"mJumpUp_totalFrames\" : " << specs.mJumpUp_totalFrames << "," << std::endl;
			file << "        \"mJumpUp_speedMultiplier\" : " << specs.mJumpUp_speedMultiplier << std::endl;

			//end of parent element
			file << "        }" << std::endl;

			//end
			file << "}";

			file.flush();
			file.close();
		}
	}

	MoveSpecs SpecsController::_LoadMoveSpecs(std::string path)
	{
		std::string str = RB::JSON::LoadJSONFile(path);

		const char* arrChar = str.c_str();

		struct json_value_s* jRoot = json_parse(arrChar, strlen(arrChar));
		struct json_object_s* jObj = json_value_as_object(jRoot);

		struct json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0); //aku move specs

		struct json_object_element_s* e0 = RB::JSON::GetElementInsideElement(*rootElement); //mCharacterType
		std::string strCharacterType = RB::JSON::GetString_FromElement(*e0);
		RB::Players::CharacterType ct = RB::Players::GetEnum(strCharacterType);

		struct json_object_element_s* e1 = e0->next; //jumpUp_totalFrames
		int32_t jumpUp_totalFrames = RB::JSON::GetInt32_FromElement(*e1);

		struct json_object_element_s* e2 = e1->next; //jumpUp_speedMultiplier
		float_t jumpUp_speedMultiplier = RB::JSON::GetFloat_FromElement(*e2); 

		struct json_object_element_s* e3 = e2->next; //jumpUp_Forward_totalFrames
		int32_t jumpUp_Forward_totalFrames = RB::JSON::GetInt32_FromElement(*e3);

		struct json_object_element_s* e4 = e3->next; //jumpUp_Forward_speedMultiplier
		float_t jumpUp_Forward_speedMultiplier = RB::JSON::GetFloat_FromElement(*e4);

		MoveSpecs specs;
		specs.mCharacterType = ct;
		specs.mJumpUp_totalFrames = jumpUp_totalFrames;
		specs.mJumpUp_speedMultiplier = jumpUp_speedMultiplier;
		specs.mJumpUp_Forward_totalFrames = jumpUp_Forward_totalFrames;
		specs.mJumpUp_Forward_speedMultiplier = jumpUp_Forward_speedMultiplier;

		_vecMoveSpecs.push_back(specs);

		return specs;
	}
}