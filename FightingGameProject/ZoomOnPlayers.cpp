#include "ZoomOnPlayers.h"

#include "Ease.h"

#include "iPlayerController.h"
#include "iCamController.h"

namespace RB::Cam
{
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
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return 0.0f;
		}

		RB::Players::iPlayer* p1 = RB::Players::iPlayerController::instance->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = RB::Players::iPlayerController::instance->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		olc::vf2d p1_pos = p1->GetPosition();
		olc::vf2d p2_pos = p2->GetPosition();
		olc::vf2d dist = p2_pos - p1_pos;

		float mag2 = dist.mag2(); //mag2 is mag * mag
		float mag = dist.mag();
		//std::cout << "mag: " << mag << " | mag2: " << mag2 << std::endl;

		return mag2;
	}

	void ZoomOnPlayers::_AutoZoom(float playerDistSq)
	{
		if (RB::Cam::iCamController::instance == nullptr)
		{
			return;
		}

		float maxSq = _maxDist * _maxDist;

		if (playerDistSq >= maxSq)
		{
			playerDistSq = maxSq;
		}

		float t = /*1.0f -*/ (playerDistSq / maxSq);

		float result = RB::EaseEquations::Ease::EaseOutSine(t);

		float zoom = _maxZoomIn * result;

		if (zoom <= _minZoomOut)
		{
			zoom = _minZoomOut;
		}

		RB::Cam::iCamController::instance->SetZoom(zoom);
	}
}