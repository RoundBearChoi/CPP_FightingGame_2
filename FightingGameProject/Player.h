#pragma once
#include <iostream>

using namespace std;

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