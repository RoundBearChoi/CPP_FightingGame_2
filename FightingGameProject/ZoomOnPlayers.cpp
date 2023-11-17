#include "ZoomOnPlayers.h"

namespace RB::Cam
{
	void ZoomOnPlayers::Init()
	{

	}

	void ZoomOnPlayers::OnFixedUpdate()
	{
		float_t sq = _GetMagSqBetweenPlayers();

		_AutoZoom(sq);
	}

	float_t ZoomOnPlayers::_GetMagSqBetweenPlayers()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return 0.0f;
		}

		RB::Players::iPlayer* p1 = RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		olc::vi2d p1_pos = p1->GetPosition();
		olc::vi2d p2_pos = p2->GetPosition();
		olc::vf2d dist = (olc::vf2d)p2_pos - (olc::vf2d)p1_pos;

		float_t mag2 = dist.mag2(); //mag2 is mag * mag
		float_t mag = dist.mag();
		//std::cout << "mag: " << mag << " | mag2: " << mag2 << std::endl;

		return mag2;
	}

	void ZoomOnPlayers::_AutoZoom(float_t playerDistSq)
	{
		if (RB::Cam::CAM_CONTROLLER == nullptr)
		{
			return;
		}

		float_t maxSq = _maxDist * _maxDist;

		if (playerDistSq >= maxSq)
		{
			playerDistSq = maxSq;
		}

		float_t t = /*1.0f -*/ (playerDistSq / maxSq);

		float_t result = RB::EaseEquations::Ease::EaseOutSine(t);

		float_t zoom = _maxZoomIn * result;

		if (zoom <= _minZoomOut)
		{
			zoom = _minZoomOut;
		}

		RB::Cam::CAM_CONTROLLER->SetZoom(zoom);
	}
}