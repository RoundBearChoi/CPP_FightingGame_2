#include "PlayerBoxEditController.h"

#include "../Render/iPlayerDebugController.h"
#include "iPlayerBoxDataController.h"

namespace RB::Collisions
{
	void PlayerBoxEditController::Init()
	{
		//INIT_CONTROLLER
	}

	void PlayerBoxEditController::OnUpdate()
	{
		_ShowMenu();

		_AddDeleteBoxOnPress(Players::PlayerID::PLAYER_1);
		_SaveOnPress();

		Render::iPlayerDebugController* playerDebugController = GET_PLAYER_DEBUG_CONTROLLER;

		if (playerDebugController != nullptr)
		{
			playerDebugController->RenderPlayerHP(false);
			playerDebugController->RenderInput(false);

			PlayerBox* currentBox = _GetCurrentBox(Players::PlayerID::PLAYER_1);

			if (currentBox == nullptr)
			{
				playerDebugController->RenderPlayerBox(false);
			}
			else
			{
				playerDebugController->RenderPlayerBox(true);

				_UpdateBoxSizeOnPress(currentBox);
			}
		}
	}

	void PlayerBoxEditController::OnFixedUpdate()
	{

	}

	void PlayerBoxEditController::_UpdateBoxSizeOnPress(Collisions::PlayerBox* currentBox)
	{
		if (currentBox == nullptr)
		{
			return;
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			currentBox->mHeight += sizeAmount * Time::GetDeltaTime();
		}

		if (jButton.bHeld)
		{
			currentBox->mHeight -= sizeAmount * Time::GetDeltaTime();
		}

		if (hButton.bHeld)
		{
			currentBox->mWidth -= sizeAmount * Time::GetDeltaTime();
		}

		if (kButton.bHeld)
		{
			currentBox->mWidth += sizeAmount * Time::GetDeltaTime();
		}

		if (currentBox->mHeight <= 0.0f)
		{
			currentBox->mHeight = 0.0f;
		}

		if (currentBox->mWidth <= 0.0f)
		{
			currentBox->mWidth = 0.0f;
		}
	}

	void PlayerBoxEditController::_AddDeleteBoxOnPress(Players::PlayerID id)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Collisions::iPlayerBoxDataController* playerBoxDataController = GET_PLAYER_BOX_DATA_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		PlayerBoxSpecs* currentSpecs = _GetCurrentSpecs(Players::PlayerID::PLAYER_1);

		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);

		Sprites::SpriteType currSpriteType = Sprites::GetCurrentSpriteType(id);

		if (insButton.bPressed)
		{
			if (currentSpecs == nullptr)
			{
				playerBoxDataController->AddSpecs(PlayerBox(Sprites::GetCurrentAnimationFrame(id), 0.0f, 0.0f, 62.0f, 124.0f), currSpriteType, playerController->GetPlayer(id)->GetCharacterType());
			}
			else
			{
				PlayerBox* existingBox = currentSpecs->GetBox_ptr(Sprites::GetCurrentAnimationFrame(id));

				if (existingBox == nullptr)
				{
					currentSpecs->AddBox(PlayerBox(Sprites::GetCurrentAnimationFrame(id), 0.0f, 0.0f, 62.0f, 124.0f));
				}
				else
				{
					//do nothing - only one box per sprite for now
				}
			}
		}

		if (delButton.bPressed)
		{
			if (currentSpecs == nullptr)
			{
				//nothing to delete	
			}
			else
			{
				Collisions::LoadedPlayerBoxData* loaded = playerBoxDataController->GetLoadedData(_GetCharacterType(id));
				loaded->EraseSpecs(Sprites::GetCurrentSpriteType(id), Sprites::GetCurrentAnimationFrame(id));
				loaded->RefreshIterators();
			}
		}
	}

	void PlayerBoxEditController::_SaveOnPress()
	{
		olc::HWButton enter = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enter.bPressed)
		{
			PlayerBoxSpecs* specs = _GetCurrentSpecs(Players::PlayerID::PLAYER_1);

			if (specs == nullptr)
			{
				return;
			}

			specs->Save();
		}
	}

	void PlayerBoxEditController::_ShowMenu()
	{
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 30 }, "PlayerBoxEditor", olc::GREEN, { 1.2f, 1.2f });

		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 50 }, "PgUp, PgDown : prev/next frame", olc::WHITE, { 0.6f, 0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 60 }, "Ins, Del : create/delete box", olc::WHITE, { 0.6f, 0.6f });

		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 90 }, "UHJK : enlarge/shrink box", olc::WHITE, { 0.6f,0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 100 }, "ENTER : save data (saves the entire set)", olc::WHITE, { 0.6f,0.6f });

		Sprites::SpriteType spriteType = Sprites::GetCurrentSpriteType(Players::PlayerID::PLAYER_1);
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 120 }, "animation name: " + std::string(spriteType._to_string()), olc::YELLOW, { 0.6f, 0.6f });
		olc::Renderer::ptrPGE->DrawStringDecal(olc::vi2d{ 10, 130 }, "animation frame: " + std::to_string(Sprites::GetCurrentAnimationFrame(Players::PlayerID::PLAYER_1)), olc::YELLOW, { 0.6f,0.6f });
	}

	PlayerBox* PlayerBoxEditController::_GetCurrentBox(Players::PlayerID id)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Collisions::iPlayerBoxDataController* playerBoxDataController = GET_PLAYER_BOX_DATA_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(id);
	
		Players::CharacterType characterType = player->GetCharacterType();
	
		if (playerBoxDataController == nullptr)
		{
			return nullptr;
		}
	
		Collisions::LoadedPlayerBoxData* loaded = playerBoxDataController->GetLoadedData(characterType);
	
		if (loaded == nullptr)
		{
			return nullptr;
		}
	
		Collisions::PlayerBox* box = loaded->GetSpecs(Sprites::GetCurrentSpriteType(id), Sprites::GetCurrentAnimationFrame(id));
	
		return box;
	}

	PlayerBoxSpecs* PlayerBoxEditController::_GetCurrentSpecs(Players::PlayerID id)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Collisions::iPlayerBoxDataController* playerBoxDataController = GET_PLAYER_BOX_DATA_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(id);
		Players::CharacterType characterType = player->GetCharacterType();

		if (playerBoxDataController == nullptr)
		{
			return nullptr;
		}

		Collisions::LoadedPlayerBoxData* loaded = playerBoxDataController->GetLoadedData(characterType);

		if (loaded == nullptr)
		{
			return nullptr;
		}

		Collisions::PlayerBoxSpecs* specs = loaded->GetSpecs(Sprites::GetCurrentSpriteType(id));

		return specs;
	}

	Players::CharacterType PlayerBoxEditController::_GetCharacterType(Players::PlayerID id)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(id);

		Players::CharacterType characterType = player->GetCharacterType();

		return characterType;
	}
}
