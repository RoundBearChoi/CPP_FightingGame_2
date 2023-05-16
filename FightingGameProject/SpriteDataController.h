#pragma once
#include <vector>
#include "ControllerBase.h"
#include "SpriteEnum.h"
#include "SpriteEnumString.h"

namespace RB::Sprites
{
	class SpriteDataController : public RB::Controllers::ControllerBase
	{
	public:
		SpriteDataController();
		~SpriteDataController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		std::vector<SpriteEnumString*> _vecEnumStrings;
	};
}