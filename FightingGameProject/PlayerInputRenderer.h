#pragma once

namespace RB::Render
{
	class PlayerInputRenderer
	{
	public:
		PlayerInputRenderer() = default;
		~PlayerInputRenderer() = default;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}