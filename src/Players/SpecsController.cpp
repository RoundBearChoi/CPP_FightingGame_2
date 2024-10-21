#include "SpecsController.h"

namespace RB::Players
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
		_LoadMoveSpecs("../resource/MoveSpecs/F0_moveSpecs.moveSpecs", RB::Players::CharacterType::AKU);
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

		return MoveSpecs{ characterType };
	}

	MoveSpecs SpecsController::_LoadMoveSpecs(std::string path, RB::Players::CharacterType characterType)
	{
		RB::JSON::JParser parser;
		parser.LoadJSON(path);

		auto jObj = parser.GetObj(0);
		auto element = RB::JSON::JParser::GetElement(*jObj, 0);
		auto subElement = RB::JSON::JParser::GetElement(*element, 0);
		auto vecAll = RB::JSON::JParser::GetAllElements(*subElement);

		float walk_Forward_Speed = RB::JSON::JParser::GetFloat_FromElement(*vecAll[0]);
		float walk_Back_Speed = RB::JSON::JParser::GetFloat_FromElement(*vecAll[1]);
		int jumpUp_totalFrames = RB::JSON::JParser::GetInt_FromElement(*vecAll[2]);
		float jumpUp_speedMultiplier = RB::JSON::JParser::GetFloat_FromElement(*vecAll[3]);
		int jumpUp_Forward_totalFrames = RB::JSON::JParser::GetInt_FromElement(*vecAll[4]);
		float jumpUp_Forward_speedMultiplier = RB::JSON::JParser::GetFloat_FromElement(*vecAll[5]);

		MoveSpecs specs;
		specs.mCharacterType = characterType;
		specs.mWalk_Forward_Speed = walk_Forward_Speed;
		specs.mWalk_Back_Speed = walk_Back_Speed;
		specs.mJumpUp_totalFrames = jumpUp_totalFrames;
		specs.mJumpUp_speedMultiplier = jumpUp_speedMultiplier;
		specs.mJumpUp_Forward_totalFrames = jumpUp_Forward_totalFrames;
		specs.mJumpUp_Forward_speedMultiplier = jumpUp_Forward_speedMultiplier;

		_vecMoveSpecs.push_back(specs);

		return specs;
	}
}
