#pragma once

#include <string>

#include "LogType.h"

#include "../Players/PlayerType.h"
#include "../Controllers/ControllerBase.h"

namespace RB::Log
{
	#define GET_LOG_CONTROLLER static_cast<Log::iLogController*>(Controllers::GetController(Controllers::ControllerType::LOG_CONTROLLER))

	class iLogController : public Controllers::ControllerBase
	{
	public:
		virtual ~iLogController() override {}
		virtual bool AddToStream(Players::PLAYER_TYPE playerID, Log::LOG_TYPE logType, const std::string& str) = 0; 
	};
}
