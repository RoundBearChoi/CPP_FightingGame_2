#include "FollowPlayers.h"

namespace RB::Cam
{
	void FollowPlayers::Init(iCamObj* cam)
	{
		_camObj = cam;
		_maxDist = 80.0f;
	}

	void FollowPlayers::OnUpdate()
	{

	}

	void FollowPlayers::OnFixedUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		Players::iPlayer* p0 = playerController->GetPlayerOnID(Players::PlayerID::PLAYER_1);
		Players::iPlayer* p1 = playerController->GetPlayerOnID(Players::PlayerID::PLAYER_2);

		if (p0 == nullptr || p1 == nullptr)
		{
			return;
		}

		float p0_pos_x = p0->GetPosition().x;
		float p1_pos_x = p1->GetPosition().x;
		float xDir = p1_pos_x - p0_pos_x;
		float mid = xDir * 0.5f;
		float result = (p0_pos_x + mid) * _camObj->GetZoom();

		float curr = _camObj->GetPosition().x;

		float xDist = result - curr;
		xDist = abs(xDist);

		if (xDist < 1.0f)
		{
			xDist = 0.0f;
		}

		float percentage = xDist / _maxDist;

		if (percentage < 0.0f)
		{
			percentage = 0.0f;
		}

		if (percentage > 1.0f)
		{
			percentage = 1.0f;
		}

		float ease = Ease::EaseOutCubic( 1.0f - percentage);

		if (ease <= 0.125f)
		{
			ease = 0.0f;
		}

		if (ease >= 1.0f)
		{
			ease = 1.0f;
		}

		//std::cout << ease << std::endl;

		float lerped = Lerp(curr, result, ease * 0.03f); //std::lerp(curr, result, ease * 0.03f);

		//y should be dynamic.. but for now
		_camObj->SetPosition(Vector2{ lerped, -115.0f });
	}
}
