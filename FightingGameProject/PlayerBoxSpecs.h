#pragma once

#include <string>

#include "SpriteEnum.h"
#include "Selector.h"
#include "PlayerBox.h"
#include "Notification.h"

namespace RB::Collisions
{
	class PlayerBoxSpecs
	{
	public:
		PlayerBoxSpecs(std::string path, RB::Sprites::SpriteEnum spriteType);
		PlayerBoxSpecs(std::string path, RB::Sprites::SpriteEnum spriteType, PlayerBox box);
		~PlayerBoxSpecs() = default;

	public:
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void AddBox(PlayerBox box);
		RB::Sprites::SpriteEnum GetSpriteType();
		RB::iSelector<PlayerBox>* GetSelector();
		bool BoxExists(unsigned int frame);
		const RB::Collisions::PlayerBox& GetBox(unsigned int frame);
		RB::Collisions::PlayerBox* GetBox_ptr(unsigned int frame);
		void Save();

	private:
		std::string _path = "";
		RB::Selector<PlayerBox> _selector;
		RB::Sprites::SpriteEnum _spriteType = RB::Sprites::SpriteEnum::NONE;
		const RB::Collisions::PlayerBox _emptyBox{ 0, 0.0f, 0.0f, 0.0f, 0.0f };
		RB::Render::Notification _notification;
	};
}