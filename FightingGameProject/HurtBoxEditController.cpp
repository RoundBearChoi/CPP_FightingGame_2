#include "HurtBoxEditController.h"

namespace RB::HurtBox
{
	void HurtBoxEditController::Init()
	{

	}

	void HurtBoxEditController::OnUpdate()
	{
		_getter_playerController.OnUpdate();
		_getter_playerAnimationController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();
		_getter_camController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr ||
			_getter_playerAnimationController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr ||
			_getter_camController.GetController() == nullptr)
		{
			return;
		}

		RB::HurtBox::HurtBoxDataSet* set = GetCurrentHurtBoxDataSet(RB::Players::PlayerID::PLAYER_1);
		RB::HurtBox::HBoxData* data = GetCurrentHurtBoxData(RB::Players::PlayerID::PLAYER_1);
		RB::Collisions::AABB* aabb = GetCurrentAABB(data);

		_SaveSet_OnPress(set);
		_Add_Delete_AABB_OnPress(data);
		_RenderCircleOnAABB(aabb, RB::Players::PlayerID::PLAYER_1);
		_EditAABB_OnPress(aabb);

	}

	void HurtBoxEditController::OnFixedUpdate()
	{

	}

	RB::HurtBox::HurtBoxDataSet* HurtBoxEditController::GetCurrentHurtBoxDataSet(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HurtBox::HurtBoxDataSet* dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);

		return dataSet;
	}

	RB::HurtBox::HBoxData* HurtBoxEditController::GetCurrentHurtBoxData(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HurtBox::HurtBoxDataSet* dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);
		RB::HurtBox::HBoxData* data = dataSet->GetHurtBoxDataByFrame(currentIndex);

		return data;
	}

	RB::Collisions::AABB* HurtBoxEditController::GetCurrentAABB(RB::HurtBox::HBoxData* data)
	{
		size_t count = data->GetAABBCount();

		_UpdateSelectedIndex_OnPress(count);

		for (size_t i = 0; i < count; i++)
		{
			if (i == _selectedIndex)
			{
				RB::Collisions::AABB& aabb = data->GetAABB(i);

				return &aabb;
			}
		}

		return nullptr;
	}

	void HurtBoxEditController::_RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vf2d pos = player->GetPosition() + aabb->GetBottomLeft();

		olc::vi2d relPos = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(pos) + olc::vi2d{1, -1};

		olc::Renderer::ptrPGE->DrawCircle(relPos, 3, olc::WHITE);
		olc::Renderer::ptrPGE->DrawCircle(relPos, 4, olc::WHITE);
	}

	void HurtBoxEditController::_Add_Delete_AABB_OnPress(RB::HurtBox::HBoxData* data)
	{
		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);

		if (insButton.bPressed)
		{
			data->AddAABB(RB::Collisions::AABB{ -25.0f, 25.0f, 50.0f, 50.0f });

			_selectedIndex = data->GetAABBCount() - 1;
		}

		if (delButton.bPressed)
		{
			if (data->DeleteAABB(_selectedIndex))
			{
				_selectedIndex--;
			}
		}
	}

	void HurtBoxEditController::_EditAABB_OnPress(RB::Collisions::AABB* aabb)
	{
		if (aabb == nullptr)
		{
			return;
		}

		olc::HWButton wButton = olc::Platform::ptrPGE->GetKey(olc::W);
		olc::HWButton sButton = olc::Platform::ptrPGE->GetKey(olc::S);

		olc::HWButton aButton = olc::Platform::ptrPGE->GetKey(olc::A);
		olc::HWButton dButton = olc::Platform::ptrPGE->GetKey(olc::D);

		float_t moveAmount = 50.0f;

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

		float_t sizeAmount = 40.0f;

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

	void HurtBoxEditController::_UpdateSelectedIndex_OnPress(size_t count)
	{
		olc::HWButton oButton = olc::Platform::ptrPGE->GetKey(olc::O);
		olc::HWButton pButton = olc::Platform::ptrPGE->GetKey(olc::P);

		if (oButton.bPressed)
		{
			_selectedIndex--;
		}

		if (pButton.bPressed)
		{
			_selectedIndex++;
		}

		if (_selectedIndex == SIZE_MAX)
		{
			_selectedIndex = count - 1;
		}
		else if (_selectedIndex >= count)
		{
			_selectedIndex = 0;
		}
	}
	void HurtBoxEditController::_SaveSet_OnPress(RB::HurtBox::HurtBoxDataSet* set)
	{
		olc::HWButton enterButton = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enterButton.bPressed)
		{
			std::cout << std::endl;
			std::cout << "saving hurtbox set" << std::endl;

			const std::string& path = _getter_hurtBoxDataController.GetController()->GetPath(set->GetSpriteEnum());

			std::ofstream file(path);

			if (file.is_open())
			{
				//start of whole obj
				file << "{" << std::endl;

				for (size_t f = 0; f < set->GetSize(); f++)
				{
					HBoxData* data = set->GetHurtBoxDataByFrame(f);
					const std::string& frameName = data->GetFrameName();

					file << "    \"" << frameName << "\":" << std::endl;
					file << "    [" << std::endl;

					for (size_t a = 0; a < data->GetAABBCount(); a++)
					{
						RB::Collisions::AABB aabb = data->GetAABB(a);

						file << "        {" << std::endl;
						file << "        \"posX\" : " << aabb.GetBottomLeft().x << "," << std::endl;
						file << "        \"posY\" : " << aabb.GetBottomLeft().y << "," << std::endl;
						file << "        \"width\" : " << aabb.GetWidthHeight().x << "," << std::endl;
						file << "        \"height\" : " << aabb.GetWidthHeight().y << std::endl;
						
						if (a != data->GetAABBCount() - 1)
						{
							file << "        }," << std::endl;
						}
						else
						{
							file << "        }" << std::endl;
						}
					}

					if (f != set->GetSize() - 1)
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
		}
	}
}