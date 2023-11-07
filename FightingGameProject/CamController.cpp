#include "CamController.h"

namespace RB::Cam
{
	CamController::CamController()
	{
		SetHash(typeid(*this));

		CAM_CONTROLLER = this;
	}

	CamController::~CamController()
	{
		CAM_CONTROLLER = nullptr;
	}

	void CamController::Init()
	{
		_camObj.Init();

		_followPlayers.Init(&_camObj);
	}

	void CamController::OnUpdate()
	{
		if (_allowManualControl)
		{
			_camObj.ManualUpdate();
		}
		else
		{
			_followPlayers.OnUpdate();
		}
	}

	void CamController::OnFixedUpdate()
	{
		if (_allowManualControl)
		{
			_camObj.ManualFixedUpdate();
		}
		else
		{
			_followPlayers.OnFixedUpdate();

			_GetDistanceBetweenPlayers();
		}
	}

	void CamController::SetZoom(float_t zoom)
	{
		_camObj.SetZoom(zoom);
	}

	iCamObj* CamController::GetCamObj()
	{
		return &_camObj;
	}

	void CamController::AllowManualControl(bool toggle)
	{
		_allowManualControl = toggle;
	}

	float_t CamController::_GetDistanceBetweenPlayers()
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
		//float_t mag = dist.mag();
		//std::cout << "mag: " << mag << " | mag2: " << mag2 << std::endl;


	}
}