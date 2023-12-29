#include "HBoxEditController.h"

namespace RB::HBox
{
	HBoxEditController::HBoxEditController(RB::HBox::HBoxType boxType)
	{
		_boxType = boxType;
	}

	void HBoxEditController::Init()
	{

	}

	void HBoxEditController::OnUpdate()
	{
		if (_ControllersExist() == false)
		{
			return;
		}

		_SaveHBoxes_OnPress();
		_Add_Delete_AABB_OnPress();
		_RenderCircleOnAABB(RB::Players::PlayerID::PLAYER_1);
		_EditAABB_OnPress(RB::Players::PlayerID::PLAYER_1);
	}

	void HBoxEditController::OnFixedUpdate()
	{

	}

	RB::HBox::HBox_Layer_1* HBoxEditController::GetCurrentL1(RB::Players::PlayerID playerID, HBoxType boxType)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iAnimationObj* aniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int currentIndex = aniObj->GetCurrentIndex();

		//can get either hurtbox or hitbox
		RB::HBox::HBox_Layer_1* L1 = nullptr;

		if (boxType == HBoxType::HURT_BOX)
		{
			if (RB::HBox::iHurtBoxDataController::instance != nullptr)
			{
				L1 = RB::HBox::iHurtBoxDataController::instance->Get_L1(spriteEnum);
			}
		}
		else if (boxType == HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance != nullptr)
			{
				L1 = RB::HBox::iHitBoxDataController::instance->Get_L1(spriteEnum);
			}
		}

		return L1;
	}

	RB::HBox::HBox_Layer_0* HBoxEditController::GetCurrentHBoxData(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iAnimationObj* aniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::HBox_Layer_1* L1 = nullptr;
		
		if (_boxType == HBoxType::HURT_BOX)
		{
			L1 = RB::HBox::iHurtBoxDataController::instance->Get_L1(spriteEnum);
		}
		else if (_boxType == HBoxType::HIT_BOX)
		{
			L1 = RB::HBox::iHitBoxDataController::instance->Get_L1(spriteEnum);
		}

		if (L1 == nullptr)
		{
			return nullptr;
		}

		RB::HBox::HBox_Layer_0* data = L1->GetHBoxDataByFrame(currentIndex);

		return data;
	}

	RB::HBox::HBoxType HBoxEditController::GetHBoxType()
	{
		return _boxType;
	}

	bool HBoxEditController::_ControllersExist()
	{
		if (_boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::iHurtBoxDataController::instance == nullptr)
			{
				return false;
			}
		}
		else if (_boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance == nullptr)
			{
				return false;
			}
		}

		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Render::iPlayerAnimationController::instance == nullptr ||
			RB::HBox::iMenuController::instance == nullptr ||
			RB::Cam::iCamController::instance == nullptr)
		{
			return false;
		}

		return true;
	}

	void HBoxEditController::_UpdateSelectedIndex_OnPress(RB::HBox::HBox_Layer_0* L0)
	{
		olc::HWButton oButton = olc::Platform::ptrPGE->GetKey(olc::O);
		olc::HWButton pButton = olc::Platform::ptrPGE->GetKey(olc::P);

		if (oButton.bPressed)
		{
			L0->GetSelector()->SelectUp();
		}

		else if (pButton.bPressed)
		{
			L0->GetSelector()->SelectDown();
		}
	}

	void HBoxEditController::_RenderCircleOnAABB(RB::Players::PlayerID playerID)
	{
		RB::HBox::HBox_Layer_0* L0 = GetCurrentHBoxData(playerID);

		if (L0 == nullptr)
		{
			return;
		}

		if (L0->GetSelector()->IsEmpty())
		{
			return;
		}

		RB::Collisions::AABB* aabb = L0->GetSelector()->GetSelected();

		if (aabb == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vf2d pos = player->GetPosition() + aabb->GetBottomLeft();

		olc::vf2d relPos = RB::Cam::iCamController::instance->GetCamObj()->GetRelativePosition(pos) + olc::vi2d{ 1, -1 };

		olc::Renderer::ptrPGE->DrawCircle(relPos, 3, olc::WHITE);
		olc::Renderer::ptrPGE->DrawCircle(relPos, 4, olc::WHITE);
	}

	void HBoxEditController::_Add_Delete_AABB_OnPress()
	{
		RB::HBox::HBox_Layer_0* L0 = GetCurrentHBoxData(RB::Players::PlayerID::PLAYER_1);
		
		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);
		
		if (insButton.bPressed)
		{
			L0->GetSelector()->PushBack(RB::Collisions::AABB{ 0.0f, 0.0f, 30.0f, 30.0f });
		
			L0->GetSelector()->SelectDown();
		}
		
		if (delButton.bPressed)
		{
			L0->GetSelector()->EraseSelected();
		}
	}

	void HBoxEditController::_EditAABB_OnPress(RB::Players::PlayerID playerID)
	{
		RB::HBox::HBox_Layer_0* L0 = GetCurrentHBoxData(playerID);

		if (L0 == nullptr)
		{
			return;
		}

		_UpdateSelectedIndex_OnPress(L0);

		RB::Collisions::AABB* aabb = L0->GetSelector()->GetSelected();

		if (aabb == nullptr)
		{
			return;
		}

		olc::HWButton wButton = olc::Platform::ptrPGE->GetKey(olc::W);
		olc::HWButton sButton = olc::Platform::ptrPGE->GetKey(olc::S);

		olc::HWButton aButton = olc::Platform::ptrPGE->GetKey(olc::A);
		olc::HWButton dButton = olc::Platform::ptrPGE->GetKey(olc::D);

		float moveAmount = 50.0f;

		if (wButton.bHeld)
		{
			aabb->MoveY(-moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (sButton.bHeld)
		{
			aabb->MoveY(moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (aButton.bHeld)
		{
			aabb->MoveX(-moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (dButton.bHeld)
		{
			aabb->MoveX(moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			aabb->IncreaseHeight(sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (jButton.bHeld)
		{
			aabb->IncreaseHeight(-sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (hButton.bHeld)
		{
			aabb->IncreaseWidth(-sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (kButton.bHeld)
		{
			aabb->IncreaseWidth(sizeAmount * RB::Frames::Time::GetDeltaTime());
		}
	}

	void HBoxEditController::_SaveHBoxes_OnPress()
	{
		RB::HBox::HBox_Layer_1* L1 = GetCurrentL1(RB::Players::PlayerID::PLAYER_1, _boxType);

		olc::HWButton enterButton = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enterButton.bPressed)
		{
			std::cout << std::endl;
			std::cout << "saving hurtbox set" << std::endl;

			std::string path;

			if (_boxType == RB::HBox::HBoxType::HURT_BOX)
			{
				path = RB::HBox::iHurtBoxDataController::instance->GetPath(L1->GetSpriteEnum());
			}
			else if (_boxType == RB::HBox::HBoxType::HIT_BOX)
			{
				path = RB::HBox::iHitBoxDataController::instance->GetPath(L1->GetSpriteEnum());
			}

			std::ofstream file(path);

			if (file.is_open())
			{
				//start of whole obj
				file << "{" << std::endl;

				const auto& vecL0 = L1->GetVecL0();

				for (auto i = vecL0.begin(); i != vecL0.end(); ++i)
				{
					HBox_Layer_0* L0 = (HBox_Layer_0*)&*i;
					const std::string& frameName = L0->GetFrameName();

					file << "    \"" << frameName << "\":" << std::endl;
					file << "    [" << std::endl;

					const auto& vecAABB = L0->GetSelector()->GetVector();

					for (auto i = vecAABB.begin(); i != vecAABB.end(); ++i)
					{
						RB::Collisions::AABB aabb = *i;

						file << "        {" << std::endl;
						file << "        \"posX\" : " << aabb.GetBottomLeft().x << "," << std::endl;
						file << "        \"posY\" : " << aabb.GetBottomLeft().y << "," << std::endl;
						file << "        \"width\" : " << aabb.GetWidthHeight().x << "," << std::endl;
						file << "        \"height\" : " << aabb.GetWidthHeight().y << std::endl;

						if (i != L0->GetSelector()->GetVector().end() - 1)
						{
							file << "        }," << std::endl;
						}
						else
						{
							file << "        }" << std::endl;
						}
					}

					if (i != vecL0.end() - 1)
					{
						file << "    ]," << std::endl << std::endl;
					}
					else
					{
						file << "    ]" << std::endl;
					}
				}

				//end of whole obj
				file << "}";

				file.flush();
				file.close();
			}

			RB::HBox::iMenuController::instance->ShowNotification();
		}
	}
}