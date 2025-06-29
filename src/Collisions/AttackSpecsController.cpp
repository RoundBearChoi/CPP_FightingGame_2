#include "AttackSpecsController.h"

#include "../Logger/iLogController.h"

namespace RB::Collisions
{
	void AttackSpecsController::Init()
	{
		//INIT_CONTROLLER
		
		_LoadAllAttackSpecs();
	}

	void AttackSpecsController::OnUpdate()
	{

	}

	void AttackSpecsController::OnFixedUpdate()
	{

	}

	const Collisions::AttackSpecs& AttackSpecsController::GetAttackSpecs(Sprites::SpriteType spriteType)
	{
		for (int i = 0; i < _vecAttackSpecs.size(); i++)
		{
			if (_vecAttackSpecs[i].mSpriteType._value == spriteType._value)
			{
				return _vecAttackSpecs[i];
			}
		}

		return _defaultAttackSpecs;
	}

	bool AttackSpecsController::ContainsAttackSpecs(Sprites::SpriteType spriteType)
	{
		for (int i = 0; i < _vecAttackSpecs.size(); i++)
		{
			if (_vecAttackSpecs[i].mSpriteType._value == spriteType._value)
			{
				return true;
			}
		}

		return false;
	}

	void AttackSpecsController::_LoadAllAttackSpecs()
	{
		auto logController = GET_LOG_CONTROLLER;
		
		logController->AddToStream(Players::PlayerID::NONE, Log::LOG_TYPE::LOAD_JSON, "loading fighter 0 attack specs"); 

		for (int i = Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1; i < Sprites::SpriteType::FIGHTER_0_SPRITES_END; i++)
		{
			_Load(Sprites::SpriteType::_from_index(i));
		}
	}

	void AttackSpecsController::_Load(Sprites::SpriteType spriteType)
	{
		std::string fileName = spriteType._to_string();
		fileName += ".attackSpecs";
		std::string path = "../resource/AttackSpecs/" + fileName;

		JSON::JParser parser;
	
		if (parser.LoadJSON(path) == nullptr)
		{
			return;
		}

		auto jObj = parser.GetObj(0);
		auto element = parser.GetElement(*jObj, 0);
		auto subElement = parser.GetElement(*element, 0);
		auto vecAll = parser.GetAllElements(*subElement);

		std::string strStrengthType = parser.GetString_FromElement(*vecAll[0]);
		int damageValue = parser.GetInt_FromElement(*vecAll[1]);
		int hitStopValue = parser.GetInt_FromElement(*vecAll[2]);
		int minFixedUpdatesValue = parser.GetInt_FromElement(*vecAll[3]);
		int maxHitsValue = parser.GetInt_FromElement(*vecAll[4]);
		int damageFrames = parser.GetInt_FromElement(*vecAll[5]);
		int blockFrames = parser.GetInt_FromElement(*vecAll[6]);
		int missFrames = parser.GetInt_FromElement(*vecAll[7]);

		Collisions::AttackStrengthType attackStrengthType = Collisions::AttackStrengthType::_from_string(strStrengthType.c_str());

		AttackSpecs attackSpecs;
		attackSpecs.mSpriteType = spriteType;
		attackSpecs.mAttackStrengthType = attackStrengthType;
		attackSpecs.mDamage = damageValue;
		attackSpecs.mHitStop = hitStopValue;
		attackSpecs.mMinimumFixedUpdatesSinceHit = minFixedUpdatesValue;
		attackSpecs.mMaxHits = maxHitsValue;
		attackSpecs.mDamageFrames = damageFrames;
		attackSpecs.mBlockFrames = blockFrames;
		attackSpecs.mMissFrames = missFrames;

		if (!ContainsAttackSpecs(spriteType))
		{
			_vecAttackSpecs.push_back(attackSpecs);
		}
	}
}
