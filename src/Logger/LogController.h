#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "../Writer.h"

#include "../GameFrame.h"
#include "../Updaters/Skipper.h"

#include "iLogController.h"

namespace RB::Log
{
	class LogController : public iLogController
	{
		public:
		LogController();
		~LogController() override;

		public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
		
		public:
		bool AddToStream(const std::string& str);

		// should be separated to a global func
		bool WriteToFile(const std::string& path, const std::stringstream& stream);

		private:
		void _write();

		private:
		RB::Writer _writer;
		std::stringstream* _pStringStream = nullptr;
		Updaters::Skipper _skipper;
		const std::string _logFilePath = "../GameLog.rblog";
	};
}
