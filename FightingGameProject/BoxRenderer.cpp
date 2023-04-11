#include "BoxRenderer.h"

namespace RB::Render
{
	BoxRenderer::BoxRenderer()
	{
		std::cout << "constructing BoxRenderer" << std::endl;
	}

	BoxRenderer::~BoxRenderer()
	{
		std::cout << "destroying BoxRenderer" << std::endl;
	}

	void BoxRenderer::Init()
	{
		_spriteLoader.LoadSprite("PNG files/DebugElements/whitesq_tr80.png", RB::Sprites::SpriteID::whitesq_tr80);
	}

	void BoxRenderer::RenderBox()
	{

	}
}