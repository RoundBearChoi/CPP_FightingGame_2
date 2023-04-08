#pragma once
#include "iController.h"
#include "iPlayer.h"

using namespace RB::Controllers;

namespace RB::Players
{
	class iPlayerController : public iController
	{
	public:
		virtual iPlayer* GetPlayerOnPlayerID(int ID) = 0;
	};
}