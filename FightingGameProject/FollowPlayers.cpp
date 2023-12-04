#include "FollowPlayers.h"

namespace RB::Cam
{
	void FollowPlayers::Init(iCamObj* cam)
	{
		_camObj = cam;
		_maxDist = 50.0f;
	}

	void FollowPlayers::OnUpdate()
	{

	}

	void FollowPlayers::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* p0 = RB::Players::iPlayerController::instance->GetPlayerOnIndex(0);
		RB::Players::iPlayer* p1 = RB::Players::iPlayerController::instance->GetPlayerOnIndex(1);

		if (p0 == nullptr || p1 == nullptr)
		{
			return;
		}

		int32_t p0_pos_x = p0->GetPosition().x;
		int32_t p1_pos_x = p1->GetPosition().x;
		int32_t xDir = p1_pos_x - p0_pos_x;
		float_t mid = (float_t)xDir * 0.5f;
		float_t result = ((float_t)p0_pos_x + mid) * _camObj->GetZoom();

		float_t curr = _camObj->GetPosition().x;

		float_t xDist = result - curr;
		xDist = abs(xDist);

		if (xDist < 1.0f)
		{
			xDist = 0.0f;
		}

		float_t percentage = xDist / _maxDist;

		if (percentage < 0.0f)
		{
			percentage = 0.0f;
		}

		if (percentage > 1.0f)
		{
			percentage = 1.0f;
		}

		float_t ease = RB::EaseEquations::Ease::EaseOutCubic( 1.0f - percentage);

		if (ease <= 0.125f)
		{
			ease = 0.0f;
		}

		if (ease >= 1.0f)
		{
			ease = 1.0f;
		}

		//std::cout << ease << std::endl;

		float_t lerped = std::lerp(curr, result, ease * 0.03f);

		//y should be dynamic.. but for now
		_camObj->SetPosition(olc::vf2d{ lerped, -200.0f });
	}
}