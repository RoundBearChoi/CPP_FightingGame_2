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

		olc::HWButton GetKeyBinding(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_LIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnused_Special_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnused_Movement_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		bool IsHeld(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		const std::vector<iInputObj*>& GetVecInputObjs(RB::Players::PlayerID playerID) override;
		iInputObj* GetInputByIndex(RB::Players::PlayerID playerID, unsigned int index) override;

	private:
		void _UpdateInputBuffer(RB::Players::PlayerID playerID);
		void _AddNewInputBuffer(RB::Players::PlayerID playerID, PlayerInput input, bool log);
		void _OnSpecialMove(RB::Players::PlayerID playerID, PlayerInput input);
		void _UpdateReleaseStatus(RB::Players::PlayerID playerID, PlayerInput input);
		void _AddDiagBuffer(RB::Players::PlayerID playerID, RB::Input::PlayerInput input0, RB::Input::PlayerInput input1, RB::Input::PlayerInput resultInput);
		void _UpdateDiagBufferRelease(RB::Players::PlayerID playerID, RB::Input::PlayerInput input0, RB::Input::PlayerInput input1, RB::Input::PlayerInput resultInput);
		void _DestroyOldBuffers(RB::Players::PlayerID playerID);
		void _DestroyBuffer(RB::Players::PlayerID playerID, RB::Input::PlayerInput playerInput, InfInt gameFrame);
		void _ClearAllBuffers(RB::Players::PlayerID playerID);
		std::vector<iInputObj*>& _GetInputObjs(RB::Players::PlayerID playerID);
		std::vector<SpecialMoveType>& _GetSpecialMovesInQueue(RB::Players::PlayerID playerID);
		void _TriggerSpecialMove(RB::Players::PlayerID playerID);
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
