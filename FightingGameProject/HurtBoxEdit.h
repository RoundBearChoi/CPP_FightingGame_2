#pragma once

namespace RB::HurtBox
{
	class HurtBoxEdit
	{
	public:
		HurtBoxEdit() = default;
		~HurtBoxEdit() = default;

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}