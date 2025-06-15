#pragma once

#include "iLogController.h"

namespace RB::Log
{
	class LogController : public iLogController
	{
		public:
		LogController() = default;
		~LogController() override;

		public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		public:
		bool WriteToFile(const std::string& path, const std::stringstream& stream);
	};
}
