#include "Player_HP_Renderer.h"

namespace RB::Render
{
    void Player_HP_Renderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void Player_HP_Renderer::OnUpdate()
	{
        _RenderPlayerHPBar(RB::Players::PlayerID::PLAYER_1);
        _RenderPlayerHPBar(RB::Players::PlayerID::PLAYER_2);
	}

	void Player_HP_Renderer::OnFixedUpdate()
	{

	}

    void Player_HP_Renderer::_RenderPlayerHPBar(RB::Players::PlayerID playerID)
    {
		float bar_x_size = 215.0f;
		float bar_y_size = 5.0f;

		float top_y_margin = 16.0f;
		float center_x_margin = 20.0f;

        float center_x = (512.0f * 0.5f);
        
        RB::Sprites::PivotType pivotType = RB::Sprites::PivotType::NONE;

        if (playerID == RB::Players::PlayerID::PLAYER_1)
        {
            center_x -= center_x_margin;
            pivotType = RB::Sprites::PivotType::BOTTOM_RIGHT;
        }
        else if (playerID == RB::Players::PlayerID::PLAYER_2)
        {
            center_x += center_x_margin;
            pivotType = RB::Sprites::PivotType::BOTTOM_LEFT;
        }

        RB::Players::iPlayer* player =  RB::Players::iPlayerController::Get()->GetPlayerOnID(playerID);
        int hp = player->GetHP();
        float barPercentage = (float)hp / 100.0f;

        if (barPercentage < 0.0f)
        {
            return;
        }

        _spriteContainer->RenderSprite(
			RB::Sprites::SpriteType::player_hp_bar_white, 
			bar_x_size * barPercentage,
			bar_y_size,
			RB::Vector2{ center_x, top_y_margin },
			olc::WHITE,
			pivotType, 
			false);
    }
}