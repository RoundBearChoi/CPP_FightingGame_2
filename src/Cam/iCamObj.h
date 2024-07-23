#pragma once

#include "../Vector2.h"

namespace RB::Cam
{
	class iCamObj
	{
	public:
		virtual ~iCamObj() = default;

	public:
		virtual RB::Vector2 GetPosition() = 0;
		virtual void SetPosition(RB::Vector2 pos) = 0;
		virtual void SetXPosition(float x) = 0;
		virtual void SetYPosition(float y) = 0;
		virtual RB::Vector2 GetRelativePosition(RB::Vector2 pos) = 0;
		virtual float GetZoom() = 0;
		virtual void SetZoom(float zoom) = 0;
	};
}
