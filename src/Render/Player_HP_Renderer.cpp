#include "Player_HP_Renderer.h"

namespace RB::Render
{
    void Player_HP_Renderer::Init(Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void Player_HP_Renderer::OnUpdate()
	{
        if (_render)
        {
            _RenderPlayerHPBar(Players::PLAYER_TYPE::PLAYER_1);
            _RenderPlayerHPBar(Players::PLAYER_TYPE::PLAYER_2);
        }
	}

	void Player_HP_Renderer::OnFixedUpdate()
	{
        _UpdatePlayerHPBar(Players::PLAYER_TYPE::PLAYER_1);
        _UpdatePlayerHPBar(Players::PLAYER_TYPE::PLAYER_2);

        _p1_calculator.OnFixedUpdate();
        _p2_calculator.OnFixedUpdate();
	}

    void Player_HP_Renderer::RenderHP(bool render)
    {
        _render = render;
    }

    void Player_HP_Renderer::_RenderPlayerHPBar(Players::PLAYER_TYPE playerID)
    {
		float bar_x_size = 215.0f;
		float bar_y_size = 5.0f;

		float top_y_margin = 16.0f;
		float center_x_margin = 20.0f;

        float center_x = (512.0f * 0.5f);
        
        Sprites::PivotType pivotType = Sprites::PivotType::NONE;
        EaseCalculator* calculator = nullptr;

        if (playerID._value == Players::PLAYER_TYPE::PLAYER_1)
        {
            center_x -= center_x_margin;
            pivotType = Sprites::PivotType::BOTTOM_RIGHT;
            calculator = &_p1_calculator;
        }
        else if (playerID._value == Players::PLAYER_TYPE::PLAYER_2)
        {
            center_x += center_x_margin;
            pivotType = Sprites::PivotType::BOTTOM_LEFT;
            calculator = &_p2_calculator;
        }

        float barPercentage = calculator->GetCurrentPercentage();

        if (barPercentage <= 0.001f)
        {
            return;
        }

        _spriteContainer->RenderSprite(
			Sprites::SPRITE_TYPE::player_hp_bar_white, 
			bar_x_size * barPercentage,
			bar_y_size,
			RB::Vector2{ center_x, top_y_margin },
			olc::WHITE,
			pivotType, 
			false);
    }

    void Player_HP_Renderer::_UpdatePlayerHPBar(Players::PLAYER_TYPE playerID)
    {
        EaseCalculator* calculator = nullptr;

        if (playerID._value == Players::PLAYER_TYPE::PLAYER_1)
        {
            calculator = &_p1_calculator;
        }
        else if (playerID._value == Players::PLAYER_TYPE::PLAYER_2)
        {
            calculator = &_p2_calculator;
        }

        Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

        Players::iPlayer* player =  playerController->GetPlayer(playerID);

        if (player == nullptr)
        {
            return;
        }

        float hp = (float)(player->GetHP()) * 0.01f;

        float currentBar = calculator->GetCurrentPercentage();

        if (std::abs(currentBar - hp) > 0.001f)
        {
            int speed = 40;

            // set new target
            if (calculator->GetEaseType() == EaseType::NONE)
            {
                calculator->SetTarget(speed, EaseType::EaseInSine, currentBar, hp);
            }
            // update target
            else if (calculator->GetTargetPercentage() != hp)
            {
                calculator->SetTarget(speed + calculator->GetRemainingFixedUpdateCount(), calculator->GetEaseType(), currentBar, hp);
            }
        }
        else
        {
            calculator->ClearTarget();
        }
    }
}
