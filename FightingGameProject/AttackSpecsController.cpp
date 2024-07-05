#include "AttackSpecsController.h"

#include "JGetter.h"

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

		std::string str = RB::JSON::LoadJSONFile(path);
		json_value_s* root = json_parse(str.c_str(), str.size());

		json_object_s* jObj = json_value_as_object(root);

		json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0);

		json_object_element_s* strengthType = RB::JSON::GetElementInsideElement(*rootElement); //strength type
		std::string strStrengthType = RB::JSON::GetString_FromElement(*strengthType);
		RB::Collisions::AttackStrengthType attackStrengthType = RB::Collisions::AttackStrengthType::_from_string(strStrengthType.c_str());

		json_object_element_s* damage = strengthType->next; //damage
		int damageValue = RB::JSON::GetInt_FromElement(*damage);

		json_object_element_s* hitStop = damage->next; //hit stop
		int hitStopValue = RB::JSON::GetInt_FromElement(*hitStop);

		json_object_element_s* minFixedUpdates = hitStop->next; //min fixed updates
		int minFixedUpdatesValue = RB::JSON::GetInt_FromElement(*minFixedUpdates);

		json_object_element_s* maxHits = minFixedUpdates->next; //max hits
		int maxHitsValue = RB::JSON::GetInt_FromElement(*maxHits);

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

		free(root);
	}
}