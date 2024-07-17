#include "ZoomOnPlayers.h"

#include "Vector2.h"
#include "Ease.h"

#include "iPlayerController.h"
#include "iCamController.h"

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
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return 0.0f;
		}

		RB::Players::iPlayer* p1 = RB::Players::iPlayerController::Get()->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = RB::Players::iPlayerController::Get()->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		RB::Vector2 p1_pos = p1->GetPosition();
		RB::Vector2 p2_pos = p2->GetPosition();
		RB::Vector2 dist = p2_pos - p1_pos;

		float mag2 = dist.MagnitudeSquared(); //dist.mag2(); //mag2 is mag * mag

		//float mag = dist.mag();
		//std::cout << "mag: " << mag << " | mag2: " << mag2 << std::endl;

		return mag2;
	}

	void ZoomOnPlayers::_AutoZoom(float playerDistSq)
	{
		if (RB::Cam::iCamController::Get() == nullptr)
		{
			return;
		}

		float maxSq = _maxPlayerDist * _maxPlayerDist;

		if (playerDistSq >= maxSq)
		{
			playerDistSq = maxSq;
		}

		float t = playerDistSq / maxSq;

		float result = RB::EaseEquations::Ease::EaseOutSine(t);

		float zoom = _maxZoomIn * result;

		if (zoom <= _maxZoomOut)
		{
			zoom = _maxZoomOut;
		}

		RB::Cam::iCamController::Get()->SetZoom(zoom);
	}
}
