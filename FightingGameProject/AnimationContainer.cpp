#include "AnimationContainer.h"

#include "AnimationObj.h"

#include <cassert>

namespace RB::Render
{
	AnimationContainer::~AnimationContainer()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecCurrentAnimations.clear();

		for (auto i = _vecAnimationRenderers.begin(); i != _vecAnimationRenderers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecAnimationRenderers.clear();
	}

	void AnimationContainer::Init()
	{
		_animationRendererLoader.Init();
	}

	void AnimationContainer::OnFixedUpdate()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}

	void AnimationContainer::OnUpdate()
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			RB::Players::iPlayer* p = (*i)->GetPlayer();

			if (p != nullptr)
			{
				olc::vf2d pos = p->GetPosition();

				(*i)->SetWorldPos(pos);
			}

			(*i)->RenderAnimation();
		}
	}

	bool AnimationContainer::LoadSprite(std::string path, RB::Sprites::SpriteType spriteType)
	{
		RB::Sprites::LoadedSprite* loaded = _spriteContainer.LoadSprite(path, spriteType);

		if (loaded == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	/// <summary>
	/// this function require sprites to be loaded first
	/// </summary>
	void AnimationContainer::LoadAnimation(AnimationSpecs specs)
	{
		specs.mLoadedSprite = _spriteContainer.GetLoadedSprite(specs.mSpriteType);

		assert(specs.mLoadedSprite != nullptr);

		AnimationRenderer* renderer = _animationRendererLoader.LoadAnimationRenderer(specs);

		_vecAnimationRenderers.push_back(renderer);
	}

	void AnimationContainer::DeleteAnimationObjs(RB::Players::PlayerID playerID)
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
	std::vector<iAnimationObj*>::const_iterator AnimationContainer::DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it)
	{
		iAnimationObj* obj = (*it);

		std::vector<iAnimationObj*>::iterator next = _vecCurrentAnimations.erase(it);

		delete (obj);
		obj = nullptr;

		return next;
	}

	iAnimationObj* AnimationContainer::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType)
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			if ((*i)->GetPlayer()->GetPlayerID() == playerID)
			{
				if ((*i)->GetAnimationSpecs().mSpriteType == spriteType)
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	iAnimationObj* AnimationContainer::GetCurrentAnimationObj(unsigned int index)
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
	iAnimationObj* AnimationContainer::InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteType spriteType, RB::Sprites::PivotType pivotType)
	{
		AnimationRenderer* renderer = GetAnimationRenderer(spriteType);

		iAnimationObj* animationObj = new AnimationObj(&player, renderer, pivotType);

		return animationObj;
	}

	RB::Sprites::SpriteType AnimationContainer::GetSpriteType(RB::Players::PlayerID playerID)
	{
		for (auto i = _vecCurrentAnimations.begin(); i != _vecCurrentAnimations.end(); i++)
		{
			if ((*i)->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteType spriteType = (*i)->GetAnimationSpecs().mSpriteType;

				return spriteType;
			}
		}

		return RB::Sprites::SpriteType::NONE;
	}

	void AnimationContainer::AddNewAnimation(iAnimationObj* animationObj)
	{
		_vecCurrentAnimations.push_back(animationObj);
	}

	const std::vector<iAnimationObj*>& AnimationContainer::GetVecCurrentAnimations()
	{
		return _vecCurrentAnimations;
	}

	AnimationRenderer* AnimationContainer::GetAnimationRenderer(RB::Sprites::SpriteType spriteType)
	{
		for (auto i = _vecAnimationRenderers.begin(); i != _vecAnimationRenderers.end(); i++)
		{
			if ((*i)->GetAnimationSpecs().mSpriteType == spriteType)
			{
				return (*i);
			}
		}

		return nullptr;

		//return _animationRendererLoader.GetAnimationRenderer(spriteType);
	}
}
