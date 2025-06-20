#pragma once

#include "LogType.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Log
{
	#define GET_LOG_CONTROLLER static_cast<Log::iLogController*>(Log::GetController(Controllers::ControllerType::LOG_CONTROLLER))

	class iLogController : public Controllers::ControllerBase
	{
	public:
		virtual ~iLogController() override {}
		virtual bool AddToStream(int playerIndex, RB::Log::LOG_TYPE logType, const std::string& str) = 0; 
	};
}
