#include "SpecsController.h"

namespace RB::Players::Specs
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
		//_SaveMoveSpecs("MoveSpecs/Aku_moveSpecs.moveSpecs", MoveSpecs());
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
		return MoveSpecs();
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
			file << "        \"mJumpUp_totalFrames\" : " << specs.mJumpUp_totalFrames << "," << std::endl;
			file << "        \"mJumpUp_speedMultiplier\" : " << specs.mJumpUp_speedMultiplier << std::endl;
			//file << "        \"mX_TileCount\" : " << specs.mX_TileCount << "," << std::endl; //element inside element
			//file << "        \"mY_TileCount\" : " << specs.mY_TileCount << "," << std::endl;
			//file << "        \"mTotalSprites\" : " << specs.mTotalSprites << "," << std::endl;
			//file << "        \"mSkipFixedUpdates\" : " << specs.mSkipFixedUpdates << "," << std::endl;
			//file << "        \"mRenderSizeX\" : " << specs.mRenderSize.x << "," << std::endl;
			//file << "        \"mRenderSizeY\" : " << specs.mRenderSize.y << "," << std::endl;
			//file << "        \"mSpriteEnum\" : " << RB::Sprites::GetString(specs.mSpriteEnum) << "," << std::endl;
			//file << "        \"mPlayOnce\" : " << (specs.mPlayOnce ? 1 : 0) << std::endl;

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

		struct json_object_element_s* e0 = RB::JSON::GetElementInsideElement(*rootElement); //jumpUp_totalFrames
		int32_t jumpUp_totalFrames = RB::JSON::GetInt32_FromElement(*e0);

		struct json_object_element_s* e1 = e0->next; //jumpUp_speedMultiplier
		float_t jumpUp_speedMultiplier = RB::JSON::GetFloat_FromElement(*e1); 

		MoveSpecs specs;
		specs.mJumpUp_totalFrames = jumpUp_totalFrames;
		specs.mJumpUp_speedMultiplier = jumpUp_speedMultiplier;

		return specs;
	}
}