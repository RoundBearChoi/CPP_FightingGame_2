#pragma once

#include <string>

#include "AnimationSpecs.h"
#include "AnimationContainer.h"

namespace RB::Render
{
	extern AnimationSpecs LoadAnimationSpecsFromJSON(std::string path, AnimationContainer& container);
}
