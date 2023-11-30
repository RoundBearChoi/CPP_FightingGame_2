#include "InputController.h"

namespace RB::Input
{
	InputController::InputController()
	{
		SetHash(typeid(*this));

		INPUT_CONTROLLER = this;
	}

	InputController::~InputController()
	{
		INPUT_CONTROLLER = nullptr;

		_ClearAllBuffers(RB::Players::PlayerID::PLAYER_1);
		_ClearAllBuffers(RB::Players::PlayerID::PLAYER_2);
	}

	void InputController::Init()
	{
		_totalInputTypes = static_cast<int>(PlayerInput::COUNT);

		_vecKeyBindings.reserve((size_t)PlayerInput::COUNT);

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_UP, olc::W });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_DOWN, olc::S });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_LEFT, olc::A });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_RIGHT, olc::D });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_UP, olc::U });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_DOWN, olc::J });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_LEFT, olc::H });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_RIGHT, olc::K });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::ATTACK_WEAK_PUNCH, olc::E });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::ATTACK_WEAK_PUNCH, olc::I });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_LEFT, olc::LEFT });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_RIGHT, olc::RIGHT });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_UP, olc::UP });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_DOWN, olc::DOWN });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::CAM_ZOOM_OUT, olc::COMMA });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::CAM_ZOOM_IN, olc::PERIOD });
	}

	void InputController::OnUpdate()
	{
		_UpdateInputBuffer(RB::Players::PlayerID::PLAYER_1);
		_UpdateInputBuffer(RB::Players::PlayerID::PLAYER_2);

		_DestroyOldBuffers(RB::Players::PlayerID::PLAYER_1);
		_DestroyOldBuffers(RB::Players::PlayerID::PLAYER_2);
	}

	void InputController::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecP1_InputObjs.size(); i++)
		{
			_vecP1_InputObjs[i]->OnFixedUpdate();
		}

		for (size_t i = 0; i < _vecP2_InputObjs.size(); i++)
		{
			_vecP2_InputObjs[i]->OnFixedUpdate();
		}
	}

	olc::HWButton InputController::GetKeyBinding(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		for (size_t i = 0; i < _vecKeyBindings.size(); i++)
		{
			if (_vecKeyBindings[i].GetPlayerID() == playerID)
			{
				if (_vecKeyBindings[i].GetPlayerInput() == playerInput)
				{
					olc::Key key = _vecKeyBindings[i].GetKey();
					
					olc::HWButton button = olc::Platform::ptrPGE->GetKey(key);

					return button;
				}
			}
		}

		return olc::HWButton();
	}

	iInputObj* InputController::GetInputOBJ_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i]->GetPlayerInputType() == playerInput)
			{
				return vec[i];
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetInputObj_LIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (int32_t i = vec.size() - 1; i >= 0; i--)
		{
			if (vec[i]->GetPlayerInputType() == playerInput)
			{
				return vec[i];
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetUnusedInputObj_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i]->GetPlayerInputType() == playerInput)
			{
				if (vec[i]->IsUsed() == false)
				{
					return vec[i];
				}
			}
		}

		return nullptr;
	}

	bool InputController::IsHeld(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<RB::Input::iInputObj*>* vec = nullptr;

		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			vec = &_vecP1_InputObjs;
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			vec = &_vecP2_InputObjs;
		}
		else
		{
			return false;
		}

		for (size_t i = 0; i < vec->size(); i++)
		{
			if ((*vec)[i]->GetPlayerInputType() == playerInput)
			{
				if (!(*vec)[i]->IsReleased())
				{
					return true;
				}
			}
		}

		return false;
	}

	size_t InputController::GetTotalInputCount(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vecP1_InputObjs.size();
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vecP2_InputObjs.size();
		}

		return 0;
	}

	iInputObj* InputController::GetInputByIndex(RB::Players::PlayerID playerID, size_t index)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		if (vec.size() > index)
		{
			return vec[index];
		}

		return nullptr;
	}

	void InputController::_UpdateInputBuffer(RB::Players::PlayerID playerID)
	{
		for (size_t all = 0; all < _totalInputTypes; all++)
		{
			PlayerInput input = (PlayerInput)all;

			olc::HWButton button = GetKeyBinding(playerID, input);

			if (button.bPressed)
			{
				iInputObj* obj = GetInputObj_LIFO(playerID, input);

				//add new obj if first time pressed
				if (obj == nullptr)
				{
					_AddNewInputBuffer(playerID, input);
				}

				//add 2nd obj on top of existing obj
				else
				{
					if (obj->IsReleased())
					{
						_AddNewInputBuffer(playerID, input);
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

	void InputController::_AddNewInputBuffer(RB::Players::PlayerID playerID, PlayerInput input)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		iInputObj* newObj = new InputObj(input, RB::gameFrameCount, RB::gameFrameLoopCount);

		vec.push_back(newObj);

		//std::cout << "adding player " << static_cast<int>(playerID) << " input: " << static_cast<int>(input) << std::endl;
	}

	void InputController::_UpdateReleaseStatus(RB::Players::PlayerID playerID, PlayerInput input)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i]->GetPlayerInputType() == input)
			{
				vec[i]->SetReleasedStatus(true);
			}
		}
	}

	void InputController::_DestroyOldBuffers(RB::Players::PlayerID playerID)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (int32_t i = vec.size() - 1; i >= 0; i--)
		{
			//only destroy when key is released
			if (vec[i]->IsReleased())
			{
				if (vec[i]->GetFixedUpdateCount() >= 60)
				{
					delete vec[i];
					vec[i] = nullptr;

					std::vector<iInputObj*>::iterator it;
					it = vec.begin();
					vec.erase(it + i);
				}
			}
		}
	}

	void InputController::_ClearAllBuffers(RB::Players::PlayerID playerID)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (size_t i = 0; i < vec.size(); i++)
		{
			delete vec[i];
			vec[i] = nullptr;
		}

		vec.clear();
	}

	std::vector<iInputObj*>& InputController::_GetInputObjs(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vecP1_InputObjs;
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vecP2_InputObjs;
		}

		return _vecNone;
	}
}