#include "AttackSpecsController.h"

namespace RB::Collisions
{
	void AttackSpecsController::Init()
	{
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
			//std::cout << "ERROR: failed to load JSON at path " << path << std::endl;

			return;
		}

		auto jObj = parser.GetObj(0);
		auto element = JSON::JParser::GetElement(*jObj, 0);
		auto subElement = JSON::JParser::GetElement(*element, 0);
		auto vecAll = JSON::JParser::GetAllElements(*subElement);

		std::string strStrengthType = JSON::JParser::GetString_FromElement(*vecAll[0]);
		int damageValue = JSON::JParser::GetInt_FromElement(*vecAll[1]);
		int hitStopValue = JSON::JParser::GetInt_FromElement(*vecAll[2]);
		int minFixedUpdatesValue = JSON::JParser::GetInt_FromElement(*vecAll[3]);
		int maxHitsValue = JSON::JParser::GetInt_FromElement(*vecAll[4]);

		Collisions::AttackStrengthType attackStrengthType = Collisions::AttackStrengthType::_from_string(strStrengthType.c_str());

		AttackSpecs attackSpecs;
		attackSpecs.mSpriteType = spriteType;
		attackSpecs.mAttackStrengthType = attackStrengthType;
		attackSpecs.mDamage = damageValue;
		attackSpecs.mHitStop = hitStopValue;
		attackSpecs.mMinimumFixedUpdatesSinceHit = minFixedUpdatesValue;
		attackSpecs.mMaxHits = maxHitsValue;

		if (!ContainsAttackSpecs(spriteType))
		{
			_vecAttackSpecs.push_back(attackSpecs);
		}
	}
}