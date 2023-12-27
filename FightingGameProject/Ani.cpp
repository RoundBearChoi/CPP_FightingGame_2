#include "Ani.h"

namespace RB::Render
{
	Ani::~Ani()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecCurrentAnimations.clear();
	}

	void Ani::Init()
	{
		_animationLoader.Init();
	}

	void Ani::OnFixedUpdate()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}

	void Ani::OnUpdate()
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

	void Ani::LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		_sprites.LoadSprite(path, spriteEnum);
	}

	void Ani::LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteEnum spriteEnum)
	{
		specs.mLoadedSprite = _sprites.GetLoadedSprite(spriteEnum);
		specs.mSpriteEnum = spriteEnum;

		_animationLoader.LoadAnimation(specs);
	}

	void Ani::DeleteAnimationObj(RB::Players::PlayerID playerID)
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

	void Ani::DeleteAnimationObj(unsigned int index)
	{
		if (index < _vecCurrentAnimations.size())
		{
			delete _vecCurrentAnimations[index];
			_vecCurrentAnimations[index] = nullptr;

			_vecCurrentAnimations.erase(_vecCurrentAnimations.begin() + index);
		}
	}

	/// <summary>
	/// delete element, remove from vector, and return next iterator
	/// </summary>
	std::vector<iAnimationObj*>::const_iterator Ani::DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it)
	{
		iAnimationObj* obj = (*it);

		std::vector<iAnimationObj*>::iterator next = _vecCurrentAnimations.erase(it);

		delete (obj);
		obj = nullptr;

		return next;
	}

	iAnimationObj* Ani::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum)
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

	iAnimationObj* Ani::GetCurrentAnimationObj(unsigned int index)
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
	iAnimationObj* Ani::InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteEnum playerSpriteEnum, RB::Sprites::PivotType pivotType)
	{
		iAnimationObj* animationObj = new AnimationObj(&player, _animationLoader.GetAnimationRenderer(playerSpriteEnum), pivotType);

		return animationObj;
	}

	RB::Sprites::SpriteEnum Ani::GetSpriteEnum(RB::Players::PlayerID playerID)
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

	void Ani::AddNewAnimation(iAnimationObj* animationObj)
	{
		_vecCurrentAnimations.push_back(animationObj);
	}

	const std::vector<iAnimationObj*>& Ani::GetVecCurrentAnimations()
	{
		return _vecCurrentAnimations;
	}

	AnimationRenderer* Ani::GetAnimationRenderer(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _animationLoader.GetAnimationRenderer(spriteEnum);
	}
}