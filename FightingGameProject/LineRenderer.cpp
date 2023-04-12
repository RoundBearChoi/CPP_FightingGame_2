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
		olc::vi2d screenPos1;
		olc::vi2d screenPos2;

		if (RB::Cam::CurrentCam::CamExists())
		{
			screenPos1 = RB::Cam::CurrentCam::GetRelativePos(p1);
			screenPos2 = RB::Cam::CurrentCam::GetRelativePos(p2);
		}
		else
		{
			screenPos1 = p1;
			screenPos2 = p2;
		}

		olc::Renderer::ptrPGE->DrawLine(screenPos1, screenPos2, tint);
	}
}