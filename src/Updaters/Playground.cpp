#include "Playground.h"

namespace RB::Updaters
{
	Playground::Playground()
	{
		std::function<void()> func = std::bind(&Playground::_RunCustomUpdate, this);
		_customUpdate.SetFunction(func);
	}

	Playground::~Playground()
	{
		delete _updater;
	}

	void Playground::Init()
	{
		bool firstQueueSuccessful = QueueUpdater(new GameplayUpdater());

		if (!firstQueueSuccessful)
		{
			std::cout << "first updater queue failed.. aborting.." << std::endl;

			assert(firstQueueSuccessful);
		}
	}

	void Playground::OnUpdate()
	{
		if (!_updaterIsQueued)
		{
			_updater->OnUpdate();
		}
		
		UpdateQueue();
		MakeUpdaterTransition();
	}

	void Playground::OnFixedUpdate()
	{
		bool runFixedUpdate = _customUpdate.DoFixedUpdate();

		if (runFixedUpdate)
		{
			_scheduler.OnFixedUpdate();
		}
	}

	void Playground::SetFixedUpdateSkips(int skips)
	{
		_customUpdate.SetSkipFrames(skips);
	}

	void Playground::ClearFixedUpdateSkip(int fixedUpdates)
	{
		std::function<void()> func = std::bind(&Playground::_ClearSkips, this);
		_scheduler.SetSchedule(func, fixedUpdates);
	}

	bool Playground::QueueAttackBoxEditorUpdater()
	{
		return QueueUpdater(new AttackBoxEditorUpdater());
	}

	bool Playground::QueueTargetBoxEditorUpdater()
	{
		return QueueUpdater(new TargetBoxEditorUpdater());
	}

	iUpdater* Playground::GetUpdater()
	{
		return _updater;
	}
	
	void Playground::SetUpdater(iUpdater* updater)
	{
		// delete previous updater obj
		if (_updater != nullptr)
		{
			delete _updater;

			_updater = nullptr;
		}

		// set new updater obj
		_updater = updater;

		if (_updater != nullptr)
		{
			// reset slow motion
			_customUpdate.SetSkipFrames(0);

			_updater->Init();
		}
	}

	bool Playground::QueueUpdater(iUpdater* nextUpdater)
	{
		if (nextUpdater == nullptr)
		{
			//nothing happens
			_updaterIsQueued = false;
			
			return false;
		}

		if (_updaterIsQueued)
		{
			//nothing happens (already queued)
			_updaterIsQueued = false;

			delete nextUpdater;

			return false;
		}

		//finally queue if conditions are met
		_updaterIsQueued = true;

		_nextUpdater = nextUpdater;

		return true;
	}

	void Playground::UpdateQueue()
	{
		olc::HWButton f11 = olc::Platform::ptrPGE->GetKey(olc::Key::F11);

		olc::HWButton f6 = olc::Platform::ptrPGE->GetKey(olc::Key::F6);
		olc::HWButton f7 = olc::Platform::ptrPGE->GetKey(olc::Key::F7);
		olc::HWButton f8 = olc::Platform::ptrPGE->GetKey(olc::Key::F8);

		if (f11.bPressed)
		{
			if (QueueUpdater(new GameplayUpdater()))
			{
				return;
			}
		}
		
		if (f6.bPressed)
		{
			if (QueueUpdater(new PlayerBoxEditorUpdater()))
			{
				return;
			}
		}

		if (f7.bPressed)
		{
			if (QueueAttackBoxEditorUpdater())
			{
				return;
			}
		}

		if (f8.bPressed)
		{
			if (QueueTargetBoxEditorUpdater())
			{
				return;
			}
		}
	}

	void Playground::MakeUpdaterTransition()
	{
		if (_updaterIsQueued)
		{
			_updaterIsQueued = false;

			SetUpdater(_nextUpdater);
		}
	}

	void Playground::_RunCustomUpdate()
	{
		if (!_updaterIsQueued)
		{
			bool skip = false;

			if (RB::Collisions::iGeneralHitStopController::Get() != nullptr)
			{
				if (RB::Collisions::iGeneralHitStopController::Get()->SkipFrame())
				{
					//std::cout << "skipping fixed update.." << std::endl;

					skip = true;
				}
			}

			if (!skip)
			{
				_updater->OnFixedUpdate();
			}
		}
	}

	void Playground::_ClearSkips()
	{
		_customUpdate.ClearSkipFrames();
	}
}