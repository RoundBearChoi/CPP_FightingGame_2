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

	RB::Collisions::AttackSpecs AttackSpecsController::GetAttackSpecs(RB::Sprites::SpriteType spriteType)
	{


		return RB::Collisions::AttackSpecs();
	}

	void AttackSpecsController::_LoadAttackSpecs()
	{
		_Load("AttackSpecs/aku_weak_punch.attackSpecs", RB::Sprites::SpriteType::aku_jab);
		_Load("AttackSpecs/aku_strong_punch.attackSpecs", RB::Sprites::SpriteType::aku_strong_punch);
	}

	void AttackSpecsController::_Load(const std::string& path, RB::Sprites::SpriteType spriteType)
	{
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

		int n = 0;
	}
}