#include "Ani.h"

namespace RB::Render
{
	Ani::Ani()
	{

	}

	Ani::~Ani()
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			delete _vecCurrentAnimations[i];
		}
	}

	void Ani::Init()
	{
		_animationLoader.Init();
	}

	void Ani::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			_vecCurrentAnimations[i]->OnFixedUpdate();
		}
	}

	void Ani::OnUpdate()
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			RB::Players::iPlayer* p = _vecCurrentAnimations[i]->GetPlayer();

			olc::vi2d pos = p->GetPosition();

			_vecCurrentAnimations[i]->RenderAnimation(pos);
		}
	}

	void Ani::LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteObj.LoadSprite(path, spriteEnum);
	}

	void Ani::LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteEnum spriteEnum)
	{
		specs.mLoadedSprite = _spriteObj.GetLoadedSprite(spriteEnum);

		_animationLoader.LoadAnimation(specs);
	}

	void Ani::DeleteAnimationObj(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			if (_vecCurrentAnimations[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				delete _vecCurrentAnimations[i];

				_vecCurrentAnimations.erase(_vecCurrentAnimations.begin() + i);

				return;
			}
		}
	}

	iAnimationObj* Ani::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			if (_vecCurrentAnimations[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				if (_vecCurrentAnimations[i]->GetAnimationSpecs().mSpriteEnum == spriteEnum)
				{
					return _vecCurrentAnimations[i];
				}
			}
		}

		return nullptr;
	}

	/// <summary>
	/// instantiates a new animation object, so make sure to delete it
	/// </summary>
	/// <param name="player"></param>
	/// <param name="playerSpriteEnum"></param>
	/// <returns></returns>
	iAnimationObj* Ani::GetNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteEnum playerSpriteEnum)
	{
		iAnimationObj* animationObj = new AnimationObj(&player, _animationLoader.GetAnimationRenderer(playerSpriteEnum));

		return animationObj;
	}

	RB::Sprites::SpriteEnum Ani::GetSpriteEnum(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			if (_vecCurrentAnimations[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteEnum spriteEnum = _vecCurrentAnimations[i]->GetAnimationSpecs().mSpriteEnum;

				return spriteEnum;
			}
		}

		return RB::Sprites::SpriteEnum::NONE;
	}

	void Ani::PushCurrentAnimation(iAnimationObj* animationObj)
	{
		_vecCurrentAnimations.push_back(animationObj);
	}

	size_t Ani::GetCurrentAniCount()
	{
		return _vecCurrentAnimations.size();
	}

	AnimationRenderer* Ani::GetAnimationRenderer(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _animationLoader.GetAnimationRenderer(spriteEnum);
	}
}