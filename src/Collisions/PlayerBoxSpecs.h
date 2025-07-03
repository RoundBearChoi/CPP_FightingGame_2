#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "PlayerBox.h"

#include "../Selector.h"
#include "../Sprites/SpriteType.h"
#include "../Render/Notification.h"

#include "../iSelector.h"
#include "../Writer.h"

namespace RB::Collisions
{
	class PlayerBoxSpecs
	{
	public:
		PlayerBoxSpecs(std::string path, Sprites::SpriteType spriteType);
		PlayerBoxSpecs(std::string path, Sprites::SpriteType spriteType, PlayerBox box);
		~PlayerBoxSpecs() = default;

	public:
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void AddBox(PlayerBox box);
		Sprites::SpriteType GetSpriteType();
		iSelector<PlayerBox>* GetSelector();
		bool BoxExists(unsigned int frame);
		const Collisions::PlayerBox& GetBox(unsigned int frame);
		Collisions::PlayerBox* GetBox_ptr(unsigned int frame);
		void Save();

	private:
		std::string _path = "";
		Selector<PlayerBox> _selector;
		Sprites::SpriteType _spriteType = Sprites::SpriteType::NONE;
		const Collisions::PlayerBox _emptyBox{ 0, 0.0f, 0.0f, 0.0f, 0.0f };
		Render::Notification _notification;
		RB::Writer _writer;
	};
}
