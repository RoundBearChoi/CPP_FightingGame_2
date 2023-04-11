#pragma once
#include "iCam.h"

namespace RB::Cam
{
	class CurrentCam
	{
	public:
		CurrentCam() {}
		~CurrentCam() {}

	public:
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

	private:
		static inline iCam* _cam = nullptr;
		static inline bool _camExists = false;
	};
}