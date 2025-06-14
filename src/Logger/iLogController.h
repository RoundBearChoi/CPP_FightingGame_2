#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::Log
{
	#define GET_LOG_CONTROLLER static_cast<Log::iLogController*>(Log::GetController(Controllers::ControllerType::LOG_CONTROLLER))

	class iLogController : public Controllers::ControllerBase
	{
		public:
		virtual ~iLogController() override {}

	};
}
