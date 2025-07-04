#pragma once

#include "InputObj.h"
#include "KeyBinding.h"
#include "SpecialMoveType.h"

#include "iInputController.h"
#include "iSpecialMovesController.h"

#include "../GameFrame.h"

#include "../Players/iPlayerController.h"

namespace RB::Input
{
	class InputController : public iInputController
	{
	public:
		InputController() = default;
		~InputController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		olc::HWButton GetKeyBinding(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_LIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnused_Special_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnused_Movement_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) override;
		bool IsHeld(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) override;
		const std::vector<iInputObj*>& GetVecInputObjs(Players::PLAYER_TYPE playerID) override;
		iInputObj* GetInputByIndex(Players::PLAYER_TYPE playerID, unsigned int index) override;

	private:
		void _UpdateInputBuffer(Players::PLAYER_TYPE playerID);
		void _AddNewInputBuffer(Players::PLAYER_TYPE playerID, PlayerInput input, bool log);
		void _OnSpecialMove(Players::PLAYER_TYPE playerID, PlayerInput input);
		void _UpdateReleaseStatus(Players::PLAYER_TYPE playerID, PlayerInput input);
		void _AddDiagBuffer(Players::PLAYER_TYPE playerID, Input::PlayerInput input0, Input::PlayerInput input1, Input::PlayerInput resultInput);
		void _UpdateDiagBufferRelease(Players::PLAYER_TYPE playerID, Input::PlayerInput input0, Input::PlayerInput input1, Input::PlayerInput resultInput);
		void _DestroyOldBuffers(Players::PLAYER_TYPE playerID);
		void _DestroyBuffer(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput, InfInt gameFrame);
		void _ClearAllBuffers(Players::PLAYER_TYPE playerID);
		std::vector<iInputObj*>& _GetInputObjs(Players::PLAYER_TYPE playerID);
		std::vector<SpecialMoveType>& _GetSpecialMovesInQueue(Players::PLAYER_TYPE playerID);
		void _TriggerSpecialMove(Players::PLAYER_TYPE playerID);
		void _LogInput(Players::PLAYER_TYPE playerID, iInputObj* inputObj);
		bool _DiagIsBlocking(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput);

		std::vector<KeyBinding> _vecKeyBindings;
		std::vector<iInputObj*> _vecP1_InputObjs;
		std::vector<iInputObj*> _vecP2_InputObjs;
		std::vector<iInputObj*> _vecNone_InputObjs;
		unsigned int _totalInputTypes = 0;
		std::vector<SpecialMoveType> _vecP1_SpecialMoves;
		std::vector<SpecialMoveType> _vecP2_SpecialMoves;
		std::vector<SpecialMoveType> _vecNone_SpecialMoves;
	};
}
