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
		void SetFirstAnimations(RB::Players::iPlayer& player);
		void SetNewAnimationObjsOnChange(RB::Players::iPlayer& player);
		RB::Sprites::SpriteID GetSpriteID(RB::Players::PlayerID playerID);
		void DeleteAnimationObj(RB::Players::PlayerID playerID);

	private:
		SpriteRenderer _spriteRenderer;
		AnimationLoader _animationLoader;
		std::vector<PlayerAnimationObj*> _vecPlayerAnimationObjs;
		//std::vector<RB::Players::iPlayer*> _vecPlayers;

	private:
		RB::Players::PlayerController* _playerController = nullptr;

	private:
		bool _p1_FirstAnimationExists = false;
		bool _p2_FirstAnimationExists = false;
	};
}