#include "olcPixelGameEngine.h"
#include "Updater.h"
#include "GameplayUpdater.h"
#include "HurtBoxEditorUpdater.h"

namespace RB::Updaters
{
	Updater::Updater()
	{
		std::cout << "constructing Updater" << std::endl;
	}

	Updater::~Updater()
	{
		std::cout << "destroying Updater" << std::endl;

		delete _updaterObj;
	}

	void Updater::SetUpdaterObj(iUpdaterObj* updaterObj)
	{
		//delete previous updater obj
		if (_updaterObj != nullptr)
		{
			delete _updaterObj;

			_updaterObj = nullptr;
		}

		//set new updater obj
		_updaterObj = updaterObj;

		if (_updaterObj != nullptr)
		{
			_updaterObj->Init();
		}
	}

	bool Updater::QueueUpdaterObj(iUpdaterObj* nextUpdaterObj)
	{
		if (nextUpdaterObj == nullptr)
		{
			//nothing happens
			_updaterIsQueued = false;
			
			return false;
		}

		if (_updaterIsQueued)
		{
			//nothing happens (already queued)
			_updaterIsQueued = false;

			delete nextUpdaterObj;

			return false;
		}

		//finally queue if conditions are met
		_updaterIsQueued = true;

		_nextUpdaterObj = nextUpdaterObj;

		return true;
	}

	void Updater::UpdateQueue()
	{
		olc::HWButton f11 = olc::Platform::ptrPGE->GetKey(olc::Key::F11);
		olc::HWButton f10 = olc::Platform::ptrPGE->GetKey(olc::Key::F10);

		if (f11.bPressed)
		{
			QueueUpdaterObj(new GameplayUpdater());
		}
		else if (f10.bPressed)
		{
			QueueUpdaterObj(new HurtBoxEditorUpdater());
		}
	}

	void Updater::MakeUpdaterTransition()
	{
		if (_updaterIsQueued)
		{
			_updaterIsQueued = false;

			SetUpdaterObj(_nextUpdaterObj);
		}
	}

	void Updater::Init()
	{
		QueueUpdaterObj(new GameplayUpdater());
	}

	void Updater::OnUpdate()
	{
		if (!_updaterIsQueued)
		{
			_updaterObj->OnUpdate();
		}
		
		UpdateQueue();
		MakeUpdaterTransition();
	}

	void Updater::OnFixedUpdate()
	{
		if (!_updaterIsQueued)
		{
			_updaterObj->OnFixedUpdate();
		}
	}
}