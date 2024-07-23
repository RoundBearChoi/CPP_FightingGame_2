#pragma once

#include <cmath>

#include "Players/iPlayer.h"

#include "Collisions/AABB.h"
#include "Collisions/PlayerBox.h"

#include "Players/iPlayerCollider.h"
#include "Players/iPlayerController.h"
#include "Cam/iCamController.h"

namespace RB::Players
{
	/// <summary>
	/// playerBox is the size of the playerCollider
	/// </summary>
	class PlayerCollider : public iPlayerCollider
	{
	public:
		PlayerCollider() = default;
		~PlayerCollider() = default;

	public:
		void Init(iPlayer* owner);
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		RB::Vector2 GetPlayerBox() override;
		void SetPlayerBox(const RB::Collisions::PlayerBox& box) override;
		bool IsCollidingAgainstOtherPlayer() override;
		const RB::Collisions::AABB& GetAABB() override;
		RB::Collisions::AABB* GetAABB_ptr() override;
		float* GetBodyParts() override;

	private:
		void _UpdateAABBOnPlayerPos();
		void _ResolveCollision();
		void _MovePlayers(iPlayer* otherPlayer);
		void _UpdateBodyParts();

	private:
		iPlayer* _player = nullptr;
		bool _isCollidingAgainstOtherPlayer = false;
		RB::Collisions::PlayerBox _playerBox{ 0, 0.0f, 0.0f, 0.0f, 0.0f };
		RB::Collisions::AABB _aabb{ 0, 0, 0, 0 };
		float _bodyRatio[2] = { 0.0f, 0.0f };
		float _bodyParts[2] = { 0, 0 };
	};
}
