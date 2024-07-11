#include "AttackSpecsController.h"

#include "JGetter.h"
#include "Parser.h"

namespace RB::Collisions
{
	void AttackSpecsController::Init()
	{
		_LoadAttackSpecs();
	}

	void AttackSpecsController::OnUpdate()
	{

	}

	void AttackSpecsController::OnFixedUpdate()
	{

	}

	const RB::Collisions::AttackSpecs& AttackSpecsController::GetAttackSpecs(RB::Sprites::SpriteType spriteType)
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

	bool AttackSpecsController::ContainsAttackSpecs(RB::Sprites::SpriteType spriteType)
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

	void AttackSpecsController::_LoadAttackSpecs()
	{
		_Load(RB::Sprites::SpriteType::fighter_0_jab);
		_Load(RB::Sprites::SpriteType::fighter_0_strong_punch);
		_Load(RB::Sprites::SpriteType::fighter_0_strong_kick);
	}

	void AttackSpecsController::_Load(RB::Sprites::SpriteType spriteType)
	{
		std::string fileName = spriteType._to_string();
		fileName += ".attackSpecs";
		std::string path = "AttackSpecs/" + fileName;

		RB::JSON::Parser parser;
		parser.LoadJSON(path);

		auto jObj = parser.GetObj(0);
		auto element = RB::JSON::Parser::GetElement(*jObj, 0);
		auto subElement = RB::JSON::Parser::GetElement(*element, 0);
		auto vecAll = RB::JSON::Parser::GetAllElements(*subElement);

		std::string strStrengthType = RB::JSON::GetString_FromElement(*vecAll[0]);
		int damageValue = RB::JSON::GetInt_FromElement(*vecAll[1]);
		int hitStopValue = RB::JSON::GetInt_FromElement(*vecAll[2]);
		int minFixedUpdatesValue = RB::JSON::GetInt_FromElement(*vecAll[3]);
		int maxHitsValue = RB::JSON::GetInt_FromElement(*vecAll[4]);

		RB::Collisions::AttackStrengthType attackStrengthType = RB::Collisions::AttackStrengthType::_from_string(strStrengthType.c_str());

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
