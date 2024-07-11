/*
void PixelGameEngine::EngineThread()
{
	// Add a variable to keep track of the accumulated time
	float fAccumulatedTime = 0.0f;
	const float fTargetFrameTime = 1.0f / 300.0f; // target FPS

	// Allow platform to do stuff here if needed, since its now in the
	// context of this thread
	if (platform->ThreadStartUp() == olc::FAIL) return;

	// Do engine context specific initialisation
	olc_PrepareEngine();

	// Create user resources as part of this thread
	for (auto& ext : vExtensions) ext->OnBeforeUserCreate();
	if (!OnUserCreate()) bAtomActive = false;
	for (auto& ext : vExtensions) ext->OnAfterUserCreate();

	while (bAtomActive)
	{
		// Calculate elapsed time
		float fElapsedTime = GetElapsedTime();

		// Accumulate elapsed time
		fAccumulatedTime += fElapsedTime;

		// Only update when accumulated time is greater than or equal to target frame time
		if (fAccumulatedTime >= fTargetFrameTime || fAccumulatedTime <= 0.0f)
		{
			fAccumulatedTime -= fTargetFrameTime;

			// Run as fast as possible
			while (bAtomActive) { olc_CoreUpdate(); }

			// Allow the user to free resources if they have overrided the destroy function
			if (!OnUserDestroy())
			{
				// User denied destroy for some reason, so continue running
				bAtomActive = true;
			}
		}
	}

	platform->ThreadCleanUp();
}
*/
