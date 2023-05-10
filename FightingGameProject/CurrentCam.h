#pragma once
#include "iCam.h"

namespace RB::Cam
{
	class CurrentCam
	{
	public:
		CurrentCam() = default;
		~CurrentCam() = default;

	private:
		static inline iCam* _cam = nullptr;
		static inline bool _camExists = false;

	public:
		static void Init()
		{

		}

		static void SetCurrentCam(iCam* cam)
		{
			_cam = cam;

			if (_cam != nullptr)
			{
				_camExists = true;
			}
		}

		static bool CamExists()
		{
			return _camExists;
		}

		static olc::vi2d GetRelativePos(olc::vi2d pos)
		{
			if (!_camExists)
			{
				return olc::vi2d{ 0 , 0 };
			}

			olc::vi2d rel = pos - _cam->GetPosition();

			return rel;
		}
	};
}