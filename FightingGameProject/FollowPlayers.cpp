#include "FollowPlayers.h"

namespace RB::Cam
{
	void FollowPlayers::Init(iCamObj* cam)
	{
		_camObj = cam;
	}

	void FollowPlayers::OnUpdate()
	{

	}

	void FollowPlayers::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* p0 = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(0);
		RB::Players::iPlayer* p1 = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(1);

		if (p0 == nullptr || p1 == nullptr)
		{
			return;
		}

		olc::vi2d p0_pos = p0->GetPosition();
		olc::vi2d p1_pos = p1->GetPosition();
		olc::vi2d dir = p1_pos - p0_pos;
		olc::vf2d mid = (olc::vf2d)dir * 0.5f;
		olc::vf2d result = ((olc::vf2d)p0_pos + mid) * _camObj->GetZoom();

		olc::vf2d curr = _camObj->GetPosition();

		float_t xDist = result.x - curr.x;
		xDist = abs(xDist);
		//std::cout << "x dist: " << xDist << std::endl;

		olc::vf2d lerped = curr.lerp(result, 0.05f);

		_camObj->SetPosition(lerped);

		//should be dynamic.. but for now
		_camObj->SetYPosition(-200.0f);
	}
}