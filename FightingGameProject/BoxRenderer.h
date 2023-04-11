#pragma once
#include "SpriteLoader.h"

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

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}