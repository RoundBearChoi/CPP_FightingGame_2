#pragma once

#include <string>

#include "PlayerBox.h"

#include "../Selector.h"
#include "../SpriteType.h"
#include "../Notification.h"

#include "../iSelector.h"

namespace RB::Collisions
{
	class PlayerBoxSpecs
	{
	public:
		PlayerBoxSpecs(std::string path, RB::Sprites::SpriteType spriteType);
		PlayerBoxSpecs(std::string path, RB::Sprites::SpriteType spriteType, PlayerBox box);
		~PlayerBoxSpecs() = default;

	public:
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void AddBox(PlayerBox box);
		RB::Sprites::SpriteType GetSpriteType();
		RB::iSelector<PlayerBox>* GetSelector();
		bool BoxExists(unsigned int frame);
		const RB::Collisions::PlayerBox& GetBox(unsigned int frame);
		RB::Collisions::PlayerBox* GetBox_ptr(unsigned int frame);
		void Save();

	private:
		std::string _path = "";
		RB::Selector<PlayerBox> _selector;
		RB::Sprites::SpriteType _spriteType = RB::Sprites::SpriteType::NONE;
		const RB::Collisions::PlayerBox _emptyBox{ 0, 0.0f, 0.0f, 0.0f, 0.0f };
		RB::Render::Notification _notification;
	};
}
