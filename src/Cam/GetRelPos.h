#pragma once

#include "../Vector2.h"
#include "iCamObj.h"

namespace RB::Cam
{
    extern RB::Vector2 GetRelPos(RB::Vector2 camPos, float zoom, RB::Vector2 worldPos);
    extern RB::Vector2 GetRelPos(RB::Cam::iCamObj* cam, RB::Vector2 worldPos);
}