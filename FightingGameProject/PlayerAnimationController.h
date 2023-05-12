#include "SpriteRenderer.h"
#include "AnimationLoader.h"
#include "PlayerAnimationObj.h"
#include "ControllerBase.h"
#include "ActiveControllers.h"
#include "PlayerController.h"
#include "iPlayer.h"

namespace RB::Render
{
	class PlayerAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		PlayerAnimationController();
		~PlayerAnimationController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void SetFirstAnimations();
		void SetNewAnimationObjsOnChange();
		RB::Sprites::SpriteID GetSpriteID(RB::Players::PlayerID playerID);
		void DeleteAnimationObj(RB::Players::PlayerID playerID);

	private:
		SpriteRenderer _spriteRenderer;
		AnimationLoader _animationLoader;
		std::vector<PlayerAnimationObj*> _vecPlayerAnimationObjs;
		std::vector<RB::Players::iPlayer*> _vecPlayers;

	private:
		RB::Players::PlayerController* _playerController = nullptr;
	};
}