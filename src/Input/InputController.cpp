#include "InputController.h"

#include "iSpecialMovesController.h"
#include "../Logger/iLogController.h"

namespace RB::Input
{
	InputController::~InputController()
	{
		_ClearAllBuffers(Players::PLAYER_TYPE::PLAYER_1);
		_ClearAllBuffers(Players::PLAYER_TYPE::PLAYER_2);
	}

	void InputController::Init()
	{
		//INIT_CONTROLLER

		_totalInputTypes = static_cast<unsigned int>(PlayerInput::COUNT);

		_vecP1_InputObjs.reserve(1000);
		_vecP2_InputObjs.reserve(1000);

		_vecKeyBindings.reserve((unsigned int)PlayerInput::COUNT);

		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_UP, olc::W });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_DOWN, olc::S });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_LEFT, olc::A });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_RIGHT, olc::D });

		// cam control is turned off during gameplay, so it's ok to use arrow keys
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_UP, olc::UP });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_DOWN, olc::DOWN });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_LEFT, olc::LEFT });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_RIGHT, olc::RIGHT });

		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::ATTACK_WEAK_PUNCH, olc::T });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::ATTACK_STRONG_PUNCH, olc::Y });

		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::ATTACK_WEAK_KICK, olc::G });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_1, PlayerInput::ATTACK_STRONG_KICK, olc::H });

		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::ATTACK_WEAK_PUNCH, olc::HOME });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::ATTACK_STRONG_PUNCH, olc::PGUP });

		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::ATTACK_WEAK_KICK, olc::END });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::PLAYER_2, PlayerInput::ATTACK_STRONG_KICK, olc::PGDN });

		// only allowed during editing
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::NONE, PlayerInput::MOVE_CAM_LEFT, olc::LEFT });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::NONE, PlayerInput::MOVE_CAM_RIGHT, olc::RIGHT });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::NONE, PlayerInput::MOVE_CAM_UP, olc::UP });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::NONE, PlayerInput::MOVE_CAM_DOWN, olc::DOWN });

		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::NONE, PlayerInput::CAM_ZOOM_OUT, olc::COMMA });
		_vecKeyBindings.push_back(KeyBinding{ Players::PLAYER_TYPE::NONE, PlayerInput::CAM_ZOOM_IN, olc::PERIOD });
	}

	void InputController::OnUpdate()
	{
		_UpdateInputBuffer(Players::PLAYER_TYPE::PLAYER_1);
		_UpdateInputBuffer(Players::PLAYER_TYPE::PLAYER_2);

		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_AddDiagBuffer(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_UpdateDiagBufferRelease(Players::PLAYER_TYPE::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_DestroyOldBuffers(Players::PLAYER_TYPE::PLAYER_1);
		_DestroyOldBuffers(Players::PLAYER_TYPE::PLAYER_2);
	}

	void InputController::OnFixedUpdate()
	{
		_TriggerSpecialMove(Players::PLAYER_TYPE::PLAYER_1);
		_TriggerSpecialMove(Players::PLAYER_TYPE::PLAYER_2);

		for (auto i = _vecP1_InputObjs.begin(); i != _vecP1_InputObjs.end(); ++i)
		{
			(*i)->OnFixedUpdate();
		}
		
		for (auto i = _vecP2_InputObjs.begin(); i != _vecP2_InputObjs.end(); ++i)
		{
			(*i)->OnFixedUpdate();
		}
	}

	olc::HWButton InputController::GetKeyBinding(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput)
	{
		for (auto i = _vecKeyBindings.begin(); i != _vecKeyBindings.end(); ++i)
		{
			if ((*i).GetPLAYER_TYPE() == playerID)
			{
				if ((*i).GetPlayerInput() == playerInput)
				{
					olc::Key key = (*i).GetKey();

					olc::HWButton button = olc::Platform::ptrPGE->GetKey(key);

					return button;
				}
			}
		}

		return olc::HWButton();
	}

	iInputObj* InputController::GetInputObj_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				return (*i);
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetInputObj_LIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.rbegin(); i != vec.rend(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				return (*i);
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetUnused_Special_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				if ((*i)->IsUsedAsAttack() == false)
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetUnused_Movement_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				if ((*i)->IsUsedAsMovement() == false)
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	bool InputController::IsHeld(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput)
	{
		std::vector<Input::iInputObj*>* vec = nullptr;

		if (playerID._value == Players::PLAYER_TYPE::PLAYER_1)
		{
			vec = &_vecP1_InputObjs;
		}
		else if (playerID._value == Players::PLAYER_TYPE::PLAYER_2)
		{
			vec = &_vecP2_InputObjs;
		}
		else
		{
			return false;
		}

		//reverse iterate
		for (auto i = vec->rbegin(); i != vec->rend(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				if (!(*i)->IsReleased())
				{
					return true;
				}
			}
		}

		return false;
	}

	const std::vector<iInputObj*>& InputController::GetVecInputObjs(Players::PLAYER_TYPE playerID)
	{
		if (playerID._value == Players::PLAYER_TYPE::PLAYER_1)
		{
			return _vecP1_InputObjs;
		}
		else if (playerID._value == Players::PLAYER_TYPE::PLAYER_2)
		{
			return _vecP2_InputObjs;
		}

		return _vecNone_InputObjs;
	}

	iInputObj* InputController::GetInputByIndex(Players::PLAYER_TYPE playerID, unsigned int index)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		if (vec.size() > index)
		{
			return vec[index];
		}

		return nullptr;
	}

	void InputController::_UpdateInputBuffer(Players::PLAYER_TYPE playerID)
	{
		for (int i = 0; i < _totalInputTypes; i++)
		{
			PlayerInput input = PlayerInput::_from_integral(i);

			olc::HWButton button = GetKeyBinding(playerID, input);

			if (button.bPressed || button.bHeld)
			{
				iInputObj* obj = GetInputObj_LIFO(playerID, input);

				// add new obj if first time pressed
				if (obj == nullptr)
				{
					_AddNewInputBuffer(playerID, input, button.bPressed);
				}

				//add 2nd obj on top of existing obj
				else
				{
					if (obj->IsReleased())
					{
						_AddNewInputBuffer(playerID, input, button.bPressed);
					}
				}
			}

			//set release status so 2nd obj can be added
			else if (button.bReleased)
			{
				_UpdateReleaseStatus(playerID, input);
			}
		}
	}

	void InputController::_AddNewInputBuffer(Players::PLAYER_TYPE playerID, PlayerInput input, bool log)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		iInputObj* newObj = new InputObj(input, RB::gFrame);

		vec.push_back(newObj);

		if (log)
		{
			_LogInput(playerID, newObj);
		}

		_OnSpecialMove(playerID, input);
	}

	// Check every time a punch or kick is pressed
	void InputController::_OnSpecialMove(Players::PLAYER_TYPE playerID, PlayerInput input)
	{
		auto specialMovesController = GET_SPECIAL_MOVES_CONTROLLER;

		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (specialMovesController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayer(playerID);

		if (player->IsInSpecialMoveStatus())
		{
			return;
		}

		if (input._value == PlayerInput::ATTACK_WEAK_PUNCH || input._value == PlayerInput::ATTACK_WEAK_KICK ||
			input._value == PlayerInput::ATTACK_STRONG_PUNCH || input._value == PlayerInput::ATTACK_STRONG_KICK)
		{
			Input::SpecialMoveType specialMove = specialMovesController->GetSpecialMove(playerID);

			if (specialMove != SpecialMoveType::NONE)
			{
				std::vector<SpecialMoveType>& vec = _GetSpecialMovesInQueue(playerID);

				vec.push_back(specialMove);
			}
		}
	}

	void InputController::_UpdateReleaseStatus(Players::PLAYER_TYPE playerID, PlayerInput input)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == input)
			{
				(*i)->SetReleasedStatus(true);
			}
		}
	}

	void InputController::_AddDiagBuffer(Players::PLAYER_TYPE playerID, Input::PlayerInput input0, Input::PlayerInput input1, Input::PlayerInput resultInput)
	{
		const std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		iInputObj* obj0 = nullptr;
		iInputObj* obj1 = nullptr;

		for (auto i = vec.rbegin(); i != vec.rend(); ++i)
		{
			if ((*i)->GetPlayerInputType() == input0)
			{
				obj0 = (*i);
			}

			if ((*i)->GetPlayerInputType() == input1)
			{
				obj1 = (*i);
			}

			if (obj0 != nullptr && obj1 != nullptr)
			{
				break;
			}
		}

		if (obj0 != nullptr && obj1 != nullptr)
		{
			// if both keys are held
			if (!obj0->IsReleased() && !obj1->IsReleased())
			{
				iInputObj* existing = GetInputObj_LIFO(playerID, resultInput);

				if (existing == nullptr)
				{
					_AddNewInputBuffer(playerID, resultInput, true);
				}
				else if (existing->IsReleased())
				{
					_AddNewInputBuffer(playerID, resultInput, true);
				}

				//destroy existing straight direction buffers
				//destroy both
				if (obj0->IsPressedOnSameFrameAs(obj1))
				{
					_DestroyBuffer(playerID, obj0->GetPlayerInputType(), obj0->GetGameFrameCount());
					_DestroyBuffer(playerID, obj1->GetPlayerInputType(), obj1->GetGameFrameCount());
				}
				//destroy the latter
				else if (obj0->IsPressedEarlierThan(obj1))
				{
					_DestroyBuffer(playerID, obj1->GetPlayerInputType(), obj1->GetGameFrameCount());
				}
				//destroy the latter
				else
				{
					_DestroyBuffer(playerID, obj0->GetPlayerInputType(), obj0->GetGameFrameCount());
				}
			}
		}
	}

	void InputController::_UpdateDiagBufferRelease(Players::PLAYER_TYPE playerID, Input::PlayerInput input0, Input::PlayerInput input1, Input::PlayerInput resultInput)
	{
		olc::HWButton button0 = GetKeyBinding(playerID, input0);
		olc::HWButton button1 = GetKeyBinding(playerID, input1);

		if (!button0.bHeld || !button1.bHeld)
		{
			const std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

			for (auto i = vec.begin(); i != vec.end(); ++i)
			{
				if ((*i)->GetPlayerInputType() == resultInput)
				{
					(*i)->SetReleasedStatus(true);
				}
			}
		}
	}

	void InputController::_DestroyOldBuffers(Players::PLAYER_TYPE playerID)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		auto it = vec.begin();

		while (it != vec.end())
		{
			//only destroy when key is released
			if ((*it)->IsReleased())
			{
				if ((*it)->GetFixedUpdateCount() >= 60)
				{
					delete (*it);
					(*it) = nullptr;

					it = vec.erase(it);

					continue;
				}
			}

			it++;
		}
	}

	// erase all that matches
	void InputController::_DestroyBuffer(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput, InfInt gameFrame)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		auto it = vec.begin();

		while (it != vec.end())
		{
			if ((*it)->GetPlayerInputType() == playerInput)
			{
				if ((*it)->GetGameFrameCount() == gameFrame)
				{
					delete (*it);
					(*it) = nullptr;

					it = vec.erase(it);

					continue;
				}
			}

			it++;
		}
	}

	void InputController::_ClearAllBuffers(Players::PLAYER_TYPE playerID)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vec.clear();
	}

	std::vector<iInputObj*>& InputController::_GetInputObjs(Players::PLAYER_TYPE playerID)
	{
		if (playerID._value == Players::PLAYER_TYPE::PLAYER_1)
		{
			return _vecP1_InputObjs;
		}
		else if (playerID._value == Players::PLAYER_TYPE::PLAYER_2)
		{
			return _vecP2_InputObjs;
		}

		return _vecNone_InputObjs;
	}

	std::vector<SpecialMoveType>& InputController::_GetSpecialMovesInQueue(Players::PLAYER_TYPE playerID)
	{
		if (playerID._value == Players::PLAYER_TYPE::PLAYER_1)
		{
			return _vecP1_SpecialMoves;
		}
		else if (playerID._value == Players::PLAYER_TYPE::PLAYER_2)
		{
			return _vecP2_SpecialMoves;
		}

		return _vecNone_SpecialMoves;
	}

	void InputController::_TriggerSpecialMove(Players::PLAYER_TYPE playerID)
	{
		auto playerController = GET_PLAYER_CONTROLLER;
		auto specialMovesController = GET_SPECIAL_MOVES_CONTROLLER;

		std::vector<SpecialMoveType>& vec = _GetSpecialMovesInQueue(playerID);

		if (!vec.empty())
		{
			States::iState* newState = specialMovesController->GetNewState(vec[0]);

			Players::iPlayer* player = playerController->GetPlayer(playerID);

			player->GetStateMachine()->ClearQueuedStates();
			player->GetStateMachine()->QueueNextState(newState);

			//for now, clear all (only trigger the first one assuming it's impossible to queue 2 special moves in a single update)
			vec.clear();
		}
	}

	void InputController::_LogInput(Players::PLAYER_TYPE playerID, iInputObj* inputObj)
	{
		std::string inputStr = inputObj->GetPlayerInputType()._to_string();
		
		auto logController = GET_LOG_CONTROLLER;
	
		logController->AddToStream(playerID, Log::LOG_TYPE::INPUT, inputStr);
	}
}
