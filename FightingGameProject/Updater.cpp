#include "Updater.h"

namespace RB::Engine
{
	Updater::Updater()
	{
		std::cout << "creating updater" << std::endl;
	}
	Updater::~Updater()
	{
		std::cout << "destroying updater" << std::endl;
	}

	void Updater::OnUpdate()
	{
		//std::cout << "updating.." << std::endl;
	}
}