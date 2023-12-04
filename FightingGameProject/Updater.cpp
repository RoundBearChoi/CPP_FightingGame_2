#include "Updater.h"

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

		olc::HWButton f7 = olc::Platform::ptrPGE->GetKey(olc::Key::F7);
		olc::HWButton f8 = olc::Platform::ptrPGE->GetKey(olc::Key::F8);

		if (f11.bPressed)
		{
			if (QueueUpdaterObj(new GameplayUpdater()))
			{
				return;
			}
		}
		
		if (f7.bPressed)
		{
			if (QueueUpdaterObj(new HitBoxEditorUpdater()))
			{
				return;
			}
		}

		if (f8.bPressed)
		{
			if (QueueUpdaterObj(new HurtBoxEditorUpdater()))
			{
				return;
			}
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
		bool firstQueueSuccessful = QueueUpdaterObj(new GameplayUpdater());

		if (!firstQueueSuccessful)
		{
			std::cout << "first updater queue failed.. aborting.." << std::endl;

			assert(firstQueueSuccessful);
		}
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
			bool skip = false;

			if (RB::Collisions::iGeneralHitStopController::instance != nullptr)
			{
				if (RB::Collisions::iGeneralHitStopController::instance->SkipFrame())
				{
					std::cout << "skipping fixed update.." << std::endl;
					skip = true;
				}
			}

			if (!skip)
			{
				_updaterObj->OnFixedUpdate();
			}
		}
	}
}