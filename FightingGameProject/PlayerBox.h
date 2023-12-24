#pragma once

namespace RB::Players
{
	class PlayerBox
	{
	public:
		PlayerBox() = default;
		~PlayerBox() = default;

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}