#pragma once
#include <iostream>
#include "Time.h"

using namespace std;
using namespace RB::Frames;

namespace RB::Players
{
	class Player
	{
	private:
		int _playerIndex = 0;
	public:
		Player();
		~Player();

		void Init(int playerIndex);
		void OnUpdate();
		void OnFixedUpdate();
	};
}