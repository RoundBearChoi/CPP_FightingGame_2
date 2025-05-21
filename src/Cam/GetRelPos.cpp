#include "GetRelPos.h"

#include "../DisplaySize.h"

RB::Vector2 RB::Cam::GetRelPos(RB::Vector2 camPos, float zoom, RB::Vector2 worldPos)
{
    Vector2 rel = (worldPos * zoom) - camPos;

    float displayHalfWidth = (float)displayWidth * 0.5f;
    float displayHalfHeight = (float)displayHeight * 0.5f;

    rel.x += displayHalfWidth;
    rel.y += displayHalfHeight;

    return rel;
}

RB::Vector2 GetRelPos(RB::Cam::iCamObj* cam, RB::Vector2 worldPos)
{
    RB::Vector2 rel = RB::Cam::GetRelPos(cam->GetPosition(), cam->GetZoom(), worldPos);

    return rel;
}