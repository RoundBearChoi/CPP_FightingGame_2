#include "ZoomOnPlayers.h"

namespace RB::Cam
{
	ZoomOnPlayers::ZoomOnPlayers()
	{
		_maxPlayerDist = 2000.0f;
		_maxZoomOut = 0.2f;
		_maxZoomIn = 0.6f;
	}
	void ZoomOnPlayers::Init()
	{

	}

	void ZoomOnPlayers::OnFixedUpdate()
	{
		float sq = _GetMagSqBetweenPlayers();

		_AutoZoom(sq);
	}

	float ZoomOnPlayers::_GetMagSqBetweenPlayers()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return 0.0f;
		}

		Players::iPlayer* p1 = playerController->GetPlayer(Players::PlayerID::PLAYER_1);
		Players::iPlayer* p2 = playerController->GetPlayer(Players::PlayerID::PLAYER_2);

		Vector2 p1_pos = p1->GetPosition();
		Vector2 p2_pos = p2->GetPosition();
		Vector2 dist = p2_pos - p1_pos;

		float mag2 = dist.MagnitudeSquared(); //dist.mag2(); //mag2 is mag * mag

		return mag2;
	}

	void ZoomOnPlayers::_AutoZoom(float playerDistSq)
	{
		auto camController = GET_CAM_CONTROLLER;

		if (camController == nullptr)
		{
			return;
		}

		float maxSq = _maxPlayerDist * _maxPlayerDist;

		if (playerDistSq >= maxSq)
		{
			playerDistSq = maxSq;
		}

		float t = playerDistSq / maxSq;

		float result = Ease::EaseOutSine(t);

		float zoom = _maxZoomIn * result;

		if (zoom <= _maxZoomOut)
		{
			zoom = _maxZoomOut;
		}

		camController->SetZoom(zoom);
	}
}
