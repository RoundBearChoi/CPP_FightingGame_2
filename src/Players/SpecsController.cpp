#include "SpecsController.h"
#include "MoveSpecs.h"

namespace RB::Players
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
		//INIT_CONTROLLER
		
		MoveSpecs result =  _LoadMoveSpecs("../resource/MoveSpecs/F0_moveSpecs.moveSpecs", Players::CharacterType::AKU);
	}

	void SpecsController::OnUpdate()
	{

	}

	void SpecsController::OnFixedUpdate()
	{

	}

	MoveSpecs SpecsController::GetMoveSpecs(Players::CharacterType characterType)
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

	MoveSpecs SpecsController::_LoadMoveSpecs(std::string path, Players::CharacterType characterType)
	{
		MoveSpecs specs;

		RB::JSON::JParser parser;
		parser.LoadJSON(path);

		auto jObj = parser.GetObj(0);

		if (jObj == nullptr)
		{
			return specs; // return default (empty) specs
		}

		auto element = parser.GetElement(*jObj, 0);
		auto subElement = parser.GetElement(*element, 0);
		auto vecAll = parser.GetAllElements(*subElement);

		float walk_Forward_Speed = parser.GetFloat_FromElement(*vecAll[0]);
		float walk_Back_Speed = parser.GetFloat_FromElement(*vecAll[1]);
		int jumpUp_totalFrames = parser.GetInt_FromElement(*vecAll[2]);
		float jumpUp_speedMultiplier = parser.GetFloat_FromElement(*vecAll[3]);

		int jumpForward_totalFrames = parser.GetInt_FromElement(*vecAll[4]);
		float jumpForward_horSpeedMultiplier = parser.GetFloat_FromElement(*vecAll[5]);
		float jumpForward_verSpeedMultiplier = parser.GetFloat_FromElement(*vecAll[6]);

		int jumpBack_totalFrames = parser.GetInt_FromElement(*vecAll[7]);
		float jumpBack_horSpeedMultiplier = parser.GetFloat_FromElement(*vecAll[8]);
		float jumpBack_verSpeedMultiplier = parser.GetFloat_FromElement(*vecAll[9]);

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
