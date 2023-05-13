#include "HurtBoxEditorUpdater.h"

namespace RB::Updaters
{
	HurtBoxEditorUpdater::HurtBoxEditorUpdater()
	{
		std::cout << std::endl;
		std::cout << "constructing HurtBoxEditorUpdater" << std::endl;
	}

	HurtBoxEditorUpdater::~HurtBoxEditorUpdater()
	{
		std::cout << std::endl;
		std::cout << "destructing HurtBoxEditorUpdater" << std::endl;

		RB::Controllers::ActiveControllers::OnEnd();
	}

	void HurtBoxEditorUpdater::Init()
	{
		RB::Controllers::ActiveControllers::Init();

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBE::Menu::MenuController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HurtBox::HurtBoxDataController()));
	}

	void HurtBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ActiveControllers::UpdateAll();
	}

	void HurtBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ActiveControllers::FixedUpdateAll();
	}
}