#pragma once

#include "PlayerState.h" //erase all in the end
#include "Player.h"

#include "iPlayerController.h"

namespace RB::Players
{
	class PlayerController : public iPlayerController
	{
	public:
		PlayerController() = default;
		~PlayerController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		iPlayer* AddPlayer() override;
		iPlayer* GetPlayer(PlayerID id) override;
		iPlayer* GetPlayerOnStateMachineID(unsigned int id) override;
		iPlayer* GetOtherPlayer(iPlayer* currentPlayer) override;

	private:
		void _InitOnGameplayUpdater();
		void _InitOnAttackBoxEditorUpdater();
		void _InitOnTargetBoxEditorUpdater();
	private:
		std::vector<Players::iPlayer*> _vecPlayers;
		std::string _attackBoxEditorSpritePath = "../resource/EditorSettings/AttackBoxSettings.editorSettings";
		std::string _targetBoxEditorSpritePath = "../resource/EditorSettings/TargetBoxSettings.editorSettings";
	};
}
