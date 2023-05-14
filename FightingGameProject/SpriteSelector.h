#pragma once

namespace RB::HBE::Menu
{
	class SpriteSelector
	{
	public:
		SpriteSelector() = default;
		~SpriteSelector() = default;

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}