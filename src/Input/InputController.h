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

		olc::HWButton GetKeyBinding(Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_FIFO(Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_LIFO(Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnused_Special_FIFO(Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnused_Movement_FIFO(Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		bool IsHeld(Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		const std::vector<iInputObj*>& GetVecInputObjs(Players::PlayerID playerID) override;
		iInputObj* GetInputByIndex(Players::PlayerID playerID, unsigned int index) override;

	private:
		void _UpdateInputBuffer(Players::PlayerID playerID);
		void _AddNewInputBuffer(Players::PlayerID playerID, PlayerInput input, bool log);
		void _OnSpecialMove(Players::PlayerID playerID, PlayerInput input);
		void _UpdateReleaseStatus(Players::PlayerID playerID, PlayerInput input);
		void _AddDiagBuffer(Players::PlayerID playerID, Input::PlayerInput input0, Input::PlayerInput input1, Input::PlayerInput resultInput);
		void _UpdateDiagBufferRelease(Players::PlayerID playerID, Input::PlayerInput input0, Input::PlayerInput input1, Input::PlayerInput resultInput);
		void _DestroyOldBuffers(Players::PlayerID playerID);
		void _DestroyBuffer(Players::PlayerID playerID, Input::PlayerInput playerInput, InfInt gameFrame);
		void _ClearAllBuffers(Players::PlayerID playerID);
		std::vector<iInputObj*>& _GetInputObjs(Players::PlayerID playerID);
		std::vector<SpecialMoveType>& _GetSpecialMovesInQueue(Players::PlayerID playerID);
		void _TriggerSpecialMove(Players::PlayerID playerID);
		void _LogInput(Players::PlayerID playerID, iInputObj* inputObj);
		bool _DiagIsBlocking(Players::PlayerID playerID, Input::PlayerInput playerInput);

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
