#pragma once
#include <vector>

#include "iSpriteDataController.h"

namespace RB::Sprites
{
	class SpriteDataController : public iSpriteDataController
	{
	public:
		SpriteDataController() = default;
		~SpriteDataController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		std::string _empty = "EMPTY";
	};
}