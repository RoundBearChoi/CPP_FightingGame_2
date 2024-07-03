#pragma once
#define OLC_PGE_APPLICATION 0

#include "olcPixelGameEngine.h"
#include "AllocationCount.h"
#include "GameFrame.h"
#include "Updater.h"
#include "Time.h"
#include "FixedTimer.h"
#include "DisplaySize.h"
#include "RenderLayerType.h"
#include "jsonExample.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		RB::Updaters::Updater _updater;
		RB::Frames::FixedTimer _timer;

		void _CreateLayers()
		{
			auto& layers = olc::Renderer::ptrPGE->GetLayers();

			while (layers.size() < static_cast<uint8_t>(RB::Render::RenderLayerType::COUNT))
			{
				olc::Renderer::ptrPGE->CreateLayer();

				olc::Renderer::ptrPGE->GetLayers()[layers.size() - 1].bShow = true;
				olc::Renderer::ptrPGE->GetLayers()[layers.size() - 1].bUpdate = true;
			}
		}

		void _ClearLayers()
		{
			// clear all layers with blank pixels (except top layer)
			for (int i = static_cast<uint8_t>(RB::Render::RenderLayerType::FOREGROUND); i < static_cast<uint8_t>(RB::Render::RenderLayerType::COUNT); i++)
			{
				if (olc::Renderer::ptrPGE->GetLayers()[i].bShow)
				{
					if (i == static_cast<uint8_t>(RB::Render::RenderLayerType::COUNT) - 1)
					{
						olc::Renderer::ptrPGE->SetDrawTarget(i);
						olc::Renderer::ptrPGE->Clear({ 20, 20, 20 });
					}
					else
					{
						olc::Renderer::ptrPGE->SetDrawTarget(i);
						olc::Renderer::ptrPGE->Clear(olc::BLANK);
					}
				}
			}
		}

	public:
		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			_updater.Init();

			RB::Frames::Time::ResetFixedDeltaTime();

			RB::JSON::example{}.example1();

			_CreateLayers();

			return true;
		}

		bool OnUserDestroy() override
		{
			return true;
		}

		~Game()
		{
			showAllocCount = true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			_ClearLayers();

			RB::Frames::Time::SetDeltaTime(fElapsedTime);
			RB::Frames::Time::AddFixedDeltaTime();

			_updater.OnUpdate();
			RB::AddGameFrame();

			if (_timer.DoFixedUpdate())
			{
				_updater.OnFixedUpdate();

				RB::Frames::Time::ResetFixedDeltaTime();
			}

			return true;
		}

		void Run()
		{
			if (Construct(displayWidth, displayHeight, 1, 1))
			{
				Start();
			}
		}
	};
}
