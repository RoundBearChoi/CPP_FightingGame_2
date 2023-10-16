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

		for (size_t i = 0; i < _vecInputObjs.size(); i++)
		{
			delete _vecInputObjs[i];
			_vecInputObjs[i] = nullptr;
		}

		_vecInputObjs.clear();
	}

	void InputController::Init()
	{
		_totalInputTypes = static_cast<int>(PlayerInput::COUNT);

		_vecKeyBindings.reserve((size_t)PlayerInput::COUNT);

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_LEFT, olc::A });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_RIGHT, olc::D });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::JUMP, olc::W });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_LEFT, olc::H });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_RIGHT, olc::K });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::JUMP, olc::U });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::ATTACK_LP_WEAK, olc::E });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::ATTACK_LP_WEAK, olc::I });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_LEFT, olc::LEFT });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_RIGHT, olc::RIGHT });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_UP, olc::UP });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_DOWN, olc::DOWN });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::CAM_ZOOM_OUT, olc::COMMA });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::CAM_ZOOM_IN, olc::PERIOD });
	}

	void InputController::OnUpdate()
	{
		_AddInputBuffer();
	}

	void InputController::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecInputObjs.size(); i++)
		{
			_vecInputObjs[i]->OnFixedUpdate();
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

	/// <summary>
	/// getting latest input first
	/// </summary>
	iInputObj* InputController::GetInputObj(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		for (int32_t i = _vecInputObjs.size() - 1; i >= 0; i--)
		{
			if (_vecInputObjs[i]->GetPlayerInput() == playerInput)
			{
				return _vecInputObjs[i];
			}
		}

		return nullptr;
	}

	void InputController::_AddInputBuffer()
	{
		for (size_t all = 0; all < _totalInputTypes; all++)
		{
			PlayerInput input = (PlayerInput)all;

			olc::HWButton button = GetKeyBinding(RB::Players::PlayerID::PLAYER_1, input);

			if (button.bPressed)
			{
				iInputObj* obj = GetInputObj(RB::Players::PlayerID::PLAYER_1, input);

				//add new obj
				if (obj == nullptr)
				{
					iInputObj* newObj = new InputObj(input);
					_vecInputObjs.push_back(newObj);

					std::cout << "adding input obj: " << static_cast<int>(input) << std::endl;
				}

				//add 2nd obj if released
				else
				{
					if (obj->IsReleased())
					{
						iInputObj* newObj = new InputObj(input);
						_vecInputObjs.push_back(newObj);

						std::cout << "adding input obj: " << static_cast<int>(input) << std::endl;
					}
				}
			}

			//set release status so 2nd obj can be added
			else if (button.bReleased)
			{
				for (size_t release = 0; release < _vecInputObjs.size(); release++)
				{
					if (_vecInputObjs[release]->GetPlayerInput() == input)
					{
						_vecInputObjs[release]->SetReleasedStatus(true);
					}
				}
			}
		}

		//destroy old buffers
		for (int32_t i = _vecInputObjs.size() - 1; i >= 0; i--)
		{
			if (_vecInputObjs[i]->GetFixedUpdateCount() >= 60)
			{
				//std::cout << "deleting input obj: " << static_cast<int>(_vecInputObjs[i]->GetPlayerInput()) << std::endl;

				delete _vecInputObjs[i];
				_vecInputObjs[i] = nullptr;

				std::vector<iInputObj*>::iterator it;
				it = _vecInputObjs.begin();
				_vecInputObjs.erase(it + i);
			}
		}
	}
}