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
		_spriteLoader.LoadSprite("PNG files/DebugElements/1whitesq_tr80.png");
	}

	void BoxRenderer::RenderTBox()
	{

	}
}