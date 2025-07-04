#include "GetRelPos.h"

#include "../DisplaySize.h"

namespace RB::Cam
{
	RB::Vector2 GetRelPos(RB::Vector2 camPos, float zoom, RB::Vector2 worldPos)
	{
		Vector2 rel = (worldPos * zoom) - camPos;

		float displayHalfWidth = (float)displayWidth * 0.5f;
		float displayHalfHeight = (float)displayHeight * 0.5f;

		rel.x += displayHalfWidth;
		rel.y += displayHalfHeight;

		return rel;
	}

	RB::Vector2 GetRelPos(Cam::iCamObj* cam, RB::Vector2 worldPos)
	{
		RB::Vector2 rel = Cam::GetRelPos(cam->GetPosition(), cam->GetZoom(), worldPos);

		return rel;
	}
}
