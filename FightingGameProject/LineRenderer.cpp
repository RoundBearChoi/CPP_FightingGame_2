#include "LineRenderer.h"

namespace RB::Render
{
	LineRenderer::LineRenderer()
	{
		std::cout << "constructing LineRenderer" << std::endl;
	}

	LineRenderer::~LineRenderer()
	{
		std::cout << "destroying LineRenderer" << std::endl;
	}

	void LineRenderer::Init()
	{

	}

	void LineRenderer::RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint)
	{
		if (RB::Cam::CurrentCam::CamExists())
		{
			p1 = RB::Cam::CurrentCam::GetRelativePos(p1);
			p2 = RB::Cam::CurrentCam::GetRelativePos(p2);
		}
	}
}