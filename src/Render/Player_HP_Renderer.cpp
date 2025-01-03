#include "Player_HP_Renderer.h"

namespace RB::Render
{
    void Player_HP_Renderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void Player_HP_Renderer::OnUpdate()
	{
        _RenderHPBars();
	}

	void Player_HP_Renderer::OnFixedUpdate()
	{

	}

    void Player_HP_Renderer::_RenderHPBars()
	{
		float bar_x = 215.0f;
		float bar_y = 5.0f;

		float top_y_margin = 28.0f;
		float center_x_margin = 20.0f;

		float p0_center_x = (512.0f * 0.5f) - center_x_margin;
		float p1_center_x = (512.0f * 0.5f) + center_x_margin;

		_spriteContainer->RenderSprite(
			RB::Sprites::SpriteType::player_hp_bar_white, 
			bar_x,
			bar_y,
			RB::Vector2{ p0_center_x, top_y_margin },
			olc::WHITE,
			RB::Sprites::PivotType::BOTTOM_RIGHT, 
			false);

		_spriteContainer->RenderSprite(
			RB::Sprites::SpriteType::player_hp_bar_white, 
			bar_x,
			bar_y,
			RB::Vector2{ p1_center_x, top_y_margin },
			olc::WHITE,
			RB::Sprites::PivotType::BOTTOM_LEFT, 
			false);
	}
}