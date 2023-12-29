#include "Ani.h"

namespace RB::Render
{
	AnimationLoader::~AnimationLoader()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecCurrentAnimations.clear();
	}

	void AnimationLoader::Init()
	{
		_aniLoader.Init();
	}

	void AnimationLoader::OnFixedUpdate()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}

	void AnimationLoader::OnUpdate()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			RB::Players::iPlayer* p = (*i)->GetPlayer();

			if (p != nullptr)
			{
				olc::vi2d pos = p->GetPosition();

				(*i)->SetWorldPos(pos);
			}

			(*i)->RenderAnimation();
		}
	}

	void AnimationLoader::LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteLoader.LoadSprite(path, spriteEnum);
	}

	/// <summary>
	/// this function require sprites to be loaded first
	/// </summary>
	void AnimationLoader::LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteEnum spriteEnum)
	{
		specs.mLoadedSprite = _spriteLoader.GetLoadedSprite(spriteEnum);
		specs.mSpriteEnum = spriteEnum;

		_aniLoader.LoadAnimation(specs);
	}

	void AnimationLoader::DeleteAnimationObjs(RB::Players::PlayerID playerID)
	{
		auto it = _vecCurrentAnimations.begin();

		while (it != _vecCurrentAnimations.end())
		{
			if ((*it)->GetPlayer()->GetPlayerID() == playerID)
			{
				delete (*it);
				(*it) = nullptr;

				it = _vecCurrentAnimations.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	/// <summary>
	/// delete element, remove from vector, and return next iterator
	/// </summary>
	std::vector<iAnimationObj*>::const_iterator AnimationLoader::DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it)
	{
		iAnimationObj* obj = (*it);

		std::vector<iAnimationObj*>::iterator next = _vecCurrentAnimations.erase(it);

		delete (obj);
		obj = nullptr;

		return next;
	}

	iAnimationObj* AnimationLoader::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum)
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			if ((*i)->GetPlayer()->GetPlayerID() == playerID)
			{
				if ((*i)->GetAnimationSpecs().mSpriteEnum == spriteEnum)
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	iAnimationObj* AnimationLoader::GetCurrentAnimationObj(unsigned int index)
	{
		if (index < _vecCurrentAnimations.size())
		{
			return _vecCurrentAnimations[index];
		}

		return nullptr;
	}

	/// <summary>
	/// raw pointer, make sure to delete
	/// </summary>
	iAnimationObj* AnimationLoader::InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteEnum playerSpriteEnum, RB::Sprites::PivotType pivotType)
	{
		iAnimationObj* animationObj = new AnimationObj(&player, _aniLoader.GetAnimationRenderer(playerSpriteEnum), pivotType);

		return animationObj;
	}

	RB::Sprites::SpriteEnum AnimationLoader::GetSpriteEnum(RB::Players::PlayerID playerID)
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			if ((*i)->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteEnum spriteEnum = (*i)->GetAnimationSpecs().mSpriteEnum;

				return spriteEnum;
			}
		}

		return RB::Sprites::SpriteEnum::NONE;
	}

	void AnimationLoader::AddNewAnimation(iAnimationObj* animationObj)
	{
		_vecCurrentAnimations.push_back(animationObj);
	}

	const std::vector<iAnimationObj*>& AnimationLoader::GetVecCurrentAnimations()
	{
		return _vecCurrentAnimations;
	}

	AnimationRenderer* AnimationLoader::GetAnimationRenderer(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _aniLoader.GetAnimationRenderer(spriteEnum);
	}
}