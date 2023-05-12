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

		RB::Controllers::Controllers::OnEnd();
	}

	void HurtBoxEditorUpdater::Init()
	{
		RB::Controllers::Controllers::Init();

		RB::Controllers::Controllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));
	}

	void HurtBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::Controllers::UpdateAll();
	}

	void HurtBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::Controllers::FixedUpdateAll();
	}
}