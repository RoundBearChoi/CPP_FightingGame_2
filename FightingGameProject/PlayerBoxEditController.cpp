#include "PlayerBoxEditController.h"

#include "PlayerState.h"
#include "Time.h"

#include "iPlayerController.h"
#include "iPlayerBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iPlayerDebugController.h"

namespace RB::Collisions
{
	void PlayerBoxEditController::Init()
	{

	}

	void PlayerBoxEditController::OnUpdate()
	{
		PlayerBox* currentBox = _GetCurrentBox(RB::Players::PlayerID::PLAYER_1);

		if (currentBox == nullptr)
		{
			RB::Render::iPlayerDebugController::instance->RenderPlayerBox(false);
		}
		else
		{
			RB::Render::iPlayerDebugController::instance->RenderPlayerBox(true);
		}

		_UpdateBoxSizeOnPress(currentBox);
		_AddDeleteBoxOnPress(RB::Players::PlayerID::PLAYER_1);
		_SaveOnPress();
	}

	void PlayerBoxEditController::OnFixedUpdate()
	{

	}

	void PlayerBoxEditController::_UpdateBoxSizeOnPress(RB::Collisions::PlayerBox* currentBox)
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
			currentBox->mHeight += sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (jButton.bHeld)
		{
			currentBox->mHeight -= sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (hButton.bHeld)
		{
			currentBox->mWidth -= sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (kButton.bHeld)
		{
			currentBox->mWidth += sizeAmount * RB::Frames::Time::GetDeltaTime();
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

	void PlayerBoxEditController::_AddDeleteBoxOnPress(RB::Players::PlayerID id)
	{
		PlayerBoxSpecs* currentSpecs = _GetCurrentSpecs(RB::Players::PlayerID::PLAYER_1);

		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);

		if (insButton.bPressed)
		{
			if (currentSpecs == nullptr)
			{
				RB::Collisions::iPlayerBoxDataController::instance->AddSpecs(PlayerBox(_GetCurrentFrame(id), 0.0f, 0.0f, 62.0f, 124.0f), _GetCurrentSpriteType(id), RB::Players::iPlayerController::instance->GetPlayerOnID(id)->GetCharacterType());
			}
		}

		if (delButton.bPressed)
		{

		}
	}

	void PlayerBoxEditController::_SaveOnPress()
	{

	}

	PlayerBox* PlayerBoxEditController::_GetCurrentBox(RB::Players::PlayerID id)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(id);
	
		RB::Players::CharacterType characterType = player->GetCharacterType();
	
		if (RB::Collisions::iPlayerBoxDataController::instance == nullptr)
		{
			return nullptr;
		}
	
		RB::Collisions::LoadedPlayerBoxData* loaded = RB::Collisions::iPlayerBoxDataController::instance->GetLoadedData(characterType);
	
		if (loaded == nullptr)
		{
			return nullptr;
		}
	
		RB::Collisions::PlayerBoxSpecs* specs = loaded->GetSpecs(_GetCurrentSpriteType(id), _GetCurrentFrame(id));
	
		if (specs == nullptr)
		{
			return nullptr;
		}
	
		auto* box = specs->GetBox_ptr(_GetCurrentFrame(id));
	
		if (box != nullptr)
		{
			return box;
		}
		else
		{
			return nullptr;
		}
	}

	PlayerBoxSpecs* PlayerBoxEditController::_GetCurrentSpecs(RB::Players::PlayerID id)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(id);

		RB::Players::CharacterType characterType = player->GetCharacterType();

		if (RB::Collisions::iPlayerBoxDataController::instance == nullptr)
		{
			return nullptr;
		}

		RB::Collisions::LoadedPlayerBoxData* loaded = RB::Collisions::iPlayerBoxDataController::instance->GetLoadedData(characterType);

		if (loaded == nullptr)
		{
			return nullptr;
		}

		RB::Collisions::PlayerBoxSpecs* specs = loaded->GetSpecs(_GetCurrentSpriteType(id), _GetCurrentFrame(id));

		return specs;
	}

	RB::Sprites::SpriteEnum PlayerBoxEditController::_GetCurrentSpriteType(RB::Players::PlayerID id)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return RB::Sprites::SpriteEnum::NONE;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		return spriteEnum;
	}

	unsigned int PlayerBoxEditController::_GetCurrentFrame(RB::Players::PlayerID id)
	{
		RB::Sprites::SpriteEnum spriteEnum = _GetCurrentSpriteType(id);

		RB::Render::iAnimationObj* iAniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(id, spriteEnum);

		if (iAniObj == nullptr)
		{
			return 0;
		}

		unsigned int animationIndex = iAniObj->GetCurrentIndex();

		return animationIndex;
	}
}