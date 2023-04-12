#pragma once

namespace RB::Render
{
	class iLineRenderer
	{
	public:
		virtual ~iLineRenderer() {}

	public:
		virtual void Init() = 0;
	};
}