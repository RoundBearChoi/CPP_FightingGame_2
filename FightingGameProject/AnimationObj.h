#pragma once

namespace RB::Render
{
	class AnimationObj
	{
	public:
		AnimationObj();
		~AnimationObj();

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}