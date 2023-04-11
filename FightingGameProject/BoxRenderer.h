#pragma once

namespace RB::Render
{
	class BoxRenderer
	{
	public:
		BoxRenderer();
		~BoxRenderer();

	public:
		void Init();

	public:
		void RenderTBox();
	};
}