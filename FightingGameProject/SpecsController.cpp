#include "SpecsController.h"

namespace RB::Players::Specs
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
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