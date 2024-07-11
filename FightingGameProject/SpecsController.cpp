#include "SpecsController.h"

#include <iostream>

#include "JGetter.h"
#include "Parser.h"

namespace RB::Players::Specs
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
		_LoadMoveSpecs("MoveSpecs/Aku_moveSpecs.moveSpecs", RB::Players::CharacterType::AKU);
	}

	void SpecsController::OnUpdate()
	{

	}

	void SpecsController::OnFixedUpdate()
	{

	}

	MoveSpecs SpecsController::GetMoveSpecs(RB::Players::CharacterType characterType)
	{
		for (auto i = _vecMoveSpecs.begin(); i != _vecMoveSpecs.end(); i++)
		{
			if (i->mCharacterType == characterType)
			{
				return *i;
			}
		}

		std::cout << "no specs found" << std::endl;

		return MoveSpecs(characterType);
	}

	MoveSpecs SpecsController::_LoadMoveSpecs(std::string path, RB::Players::CharacterType characterType)
	{
		//std::string str = RB::JSON::LoadJSONFile(path);
		//json_value_s* jRoot = json_parse(str.c_str(), str.length());
		//json_object_s* jObj = json_value_as_object(jRoot);

		RB::JSON::Parser parser;
		parser.LoadJSON(path);
		auto jObj = parser.GetObj(0);

		auto element = RB::JSON::Parser::GetElement(*jObj, 0);
		auto subElement = RB::JSON::Parser::GetElement(*element, 0);

		auto vecAll = RB::JSON::Parser::GetAllElements_FIXED(*subElement); //RB::JSON::Parser::GetAllElements(*jObj); //RB::JSON::GetAllElements(jObj);

		float walk_Forward_Speed = RB::JSON::GetFloat_FromElement(*vecAll[0]);
		float walk_Back_Speed = RB::JSON::GetFloat_FromElement(*vecAll[1]);
		int jumpUp_totalFrames = RB::JSON::GetInt_FromElement(*vecAll[2]);
		float jumpUp_speedMultiplier = RB::JSON::GetFloat_FromElement(*vecAll[3]);
		int jumpUp_Forward_totalFrames = RB::JSON::GetInt_FromElement(*vecAll[4]);
		float jumpUp_Forward_speedMultiplier = RB::JSON::GetFloat_FromElement(*vecAll[5]);

		MoveSpecs specs;
		specs.mCharacterType = characterType;
		specs.mWalk_Forward_Speed = walk_Forward_Speed;
		specs.mWalk_Back_Speed = walk_Back_Speed;
		specs.mJumpUp_totalFrames = jumpUp_totalFrames;
		specs.mJumpUp_speedMultiplier = jumpUp_speedMultiplier;
		specs.mJumpUp_Forward_totalFrames = jumpUp_Forward_totalFrames;
		specs.mJumpUp_Forward_speedMultiplier = jumpUp_Forward_speedMultiplier;

		_vecMoveSpecs.push_back(specs);

		//free(jRoot);

		return specs;
	}
}
