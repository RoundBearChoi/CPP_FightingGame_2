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

	void BoxRenderer::RenderBox(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType)
	{
		RB::Sprites::LoadedSprite* loadedSprite = _spriteLoader.GetLoadedSprite(RB::Sprites::SpriteID::whitesq_tr80);

		olc::vf2d half = widthHeight * 0.5f;

		std::array<olc::vf2d, 4> points;

		if (pivotType == RB::Sprites::PivotType::CENTER)
		{
			points = {
				olc::vf2d{ pos.x - half.x, pos.y - half.y },
				olc::vf2d{ pos.x - half.x, pos.y + half.y },
				olc::vf2d{ pos.x + half.x, pos.y + half.y },
				olc::vf2d{ pos.x + half.x, pos.y - half.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER)
		{
			points = {
				olc::vf2d{ pos.x - half.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x - half.x, 0.0f },
				olc::vf2d{ pos.x + half.x, 0.0f },
				olc::vf2d{ pos.x + half.x, pos.y - widthHeight.y },
			};
		}

		for (int i = 0; i < points.size(); i++)
		{
			//temp - should look for a cam so you're not dependent on gameplaycontrollers
			points[i] = RB::Controllers::GameplayControllers::GAME_CAM_CONTROLLER->GetRelativePos(points[i]);
		}
		
		olc::Decal* decal = loadedSprite->GetDecal();

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(decal, points, { 245, 245 }, { 1, 1 }, color);
	}
}