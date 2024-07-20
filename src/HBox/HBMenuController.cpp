#include "HBMenuController.h"

namespace RB::HBox
{
	void HBMenuController::Init()
	{

	}

	void HBMenuController::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Render::iPlayerAnimationController::Get() == nullptr)
		{
			return;
		}

		_ShowSavedNotification();

		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 30 }, _pageTitle, olc::GREEN, { 1.2f, 1.2f });

		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 50 }, "PgUp, PgDown : prev/next frame", olc::WHITE, { 0.6f, 0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 60 }, "Ins, Del : create/delete box", olc::WHITE, { 0.6f, 0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 70 }, "O, P : prev/next box", olc::WHITE, {0.6f, 0.6f});
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 80 }, "WASD : move box", olc::WHITE, { 0.6f, 0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 90 }, "UHJK : enlarge/shrink box", olc::WHITE, { 0.6f,0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 100 }, "ENTER : save data (saves the entire set)", olc::WHITE, { 0.6f,0.6f });

		RB::Sprites::SpriteType spriteType = RB::Sprites::GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1);
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 120 }, "animation name: " + std::string(spriteType._to_string()), olc::YELLOW, { 0.6f, 0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 130 }, "animation frame: " + std::to_string(RB::Sprites::GetCurrentAnimationFrame(RB::Players::PlayerID::PLAYER_1)), olc::YELLOW, { 0.6f,0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 140 }, "FrameName: " + _GetFrameName(), olc::YELLOW, { 0.6f, 0.6f });

		RB::HBox::Loaded_HB_Data* data = _GetHBData();

		if (data == nullptr)
		{
			return;
		}

		RB::HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(RB::Sprites::GetCurrentAnimationFrame(RB::Players::PlayerID::PLAYER_1));

		if (AABBs == nullptr)
		{
			return;
		}

		auto const& vec = AABBs->GetSelector()->GetVector();

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 340 }, "AABB count: " + std::to_string(vec.size()), olc::YELLOW);
	}

	void HBMenuController::OnFixedUpdate()
	{
		_notification.OnFixedUpdate();
	}

	void HBMenuController::ShowNotification()
	{
		_notification.AddFrameCount(120);
	}

	void HBMenuController::SetPageTitle(std::string title)
	{
		_pageTitle = title;
	}

	const std::string& HBMenuController::_GetFrameName()
	{
		RB::HBox::Loaded_HB_Data* data = _GetHBData();
		
		if (data == nullptr)
		{
			return _none;
		}

		RB::HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(RB::Sprites::GetCurrentAnimationFrame(RB::Players::PlayerID::PLAYER_1));

		if (AABBs == nullptr)
		{
			// create empty set
			data->AddSet(AABB_Set{ "frame_0" });

			AABBs = data->GetHBoxDataByFrame(RB::Sprites::GetCurrentAnimationFrame(RB::Players::PlayerID::PLAYER_1));
			//return _none;
		}

		return AABBs->GetFrameName();
	}

	RB::HBox::Loaded_HB_Data* HBMenuController::_GetHBData()
	{
		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::Get()->GetHBoxType();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (RB::HBox::iTargetBoxDataController::Get() != nullptr)
			{
				data = RB::HBox::iTargetBoxDataController::Get()->GetData(RB::Sprites::GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1));
			}
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (RB::HBox::iAttackBoxDataController::Get() != nullptr)
			{
				data = RB::HBox::iAttackBoxDataController::Get()->GetData(RB::Sprites::GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1));
			}
		}

		return data;
	}

	void HBMenuController::_ShowSavedNotification()
	{
		if (_notification.GetFrameCount() == 0)
		{
			return;
		}

		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::Get()->GetHBoxType();

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (RB::HBox::iTargetBoxDataController::Get() != nullptr)
			{
				const std::string& path = RB::HBox::iTargetBoxDataController::Get()->GetPath(RB::Sprites::GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1));
				_notification.OnUpdate("File saved: " + path);
			}
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (RB::HBox::iAttackBoxDataController::Get() != nullptr)
			{
				const std::string& path = RB::HBox::iAttackBoxDataController::Get()->GetPath(RB::Sprites::GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1));
				_notification.OnUpdate("File saved: " + path);
			}
		}
	}
}
