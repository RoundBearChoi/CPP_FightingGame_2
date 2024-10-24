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

		int jumpForward_totalFrames = RB::JSON::JParser::GetInt_FromElement(*vecAll[4]);
		float jumpForward_horSpeedMultiplier = RB::JSON::JParser::GetFloat_FromElement(*vecAll[5]);
		float jumpForward_verSpeedMultiplier = RB::JSON::JParser::GetFloat_FromElement(*vecAll[6]);

		int jumpBack_totalFrames = RB::JSON::JParser::GetInt_FromElement(*vecAll[7]);
		float jumpBack_horSpeedMultiplier = RB::JSON::JParser::GetFloat_FromElement(*vecAll[8]);
		float jumpBack_verSpeedMultiplier = RB::JSON::JParser::GetFloat_FromElement(*vecAll[9]);

		MoveSpecs specs;
		specs.mCharacterType = characterType;
		specs.mWalk_Forward_Speed = walk_Forward_Speed;
		specs.mWalk_Back_Speed = walk_Back_Speed;
		specs.mJumpUp_totalFrames = jumpUp_totalFrames;
		specs.mJumpUp_speedMultiplier = jumpUp_speedMultiplier;

		specs.mJumpForward_totalFrames = jumpForward_totalFrames;
		specs.mJumpForward_horSpeedMultiplier = jumpForward_horSpeedMultiplier;
		specs.mJumpForward_verSpeedMultiplier = jumpForward_verSpeedMultiplier;

		specs.mJumpBack_totalFrames = jumpBack_totalFrames;
		specs.mJumpBack_horSpeedMultiplier = jumpBack_horSpeedMultiplier;
		specs.mJumpBack_verSpeedMultiplier = jumpBack_verSpeedMultiplier;

		_vecMoveSpecs.push_back(specs);

		return specs;
	}
}
