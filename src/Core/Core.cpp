#include "Core.hpp"
#include "raylib.h"
#include <memory>

#include "../Singletons/CoreState.hpp"
#include "../Screens/MainMenu.hpp"

#define DEFAULT_WINDOWED_RESOLUTION_WIDTH 720
#define DEFAULT_WINDOWED_RESOLUTION_HEIGHT 576
#define WINDOW_TITLE "Ray Craft"

// Runs at the start of the loop
// Checks if the current screen is changed then switch to it safely
void switchScreenSafely()
{
	CoreState *state = CoreState::getInstance();
	
	if (state->changeScreen)
	{
		state->currentScreen = state->newScreen;
		state->changeScreen = false;
	}
}

namespace Core
{
	void initGame()
	{
		InitWindow
		(
			DEFAULT_WINDOWED_RESOLUTION_WIDTH,
			DEFAULT_WINDOWED_RESOLUTION_HEIGHT,
			WINDOW_TITLE
		);
		SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
		
		// Disable Exit Key
		SetExitKey(0);
		
		SetTargetFPS(60);
		CoreState *state = CoreState::getInstance();
		state->setCurrentScreen(std::dynamic_pointer_cast<Screen, MainMenu> (std::make_shared<MainMenu>()));
	}

	void runLoop()
	{
		CoreState *state = CoreState::getInstance();

		while(!state->shouldExit)
		{
			// If Current Screen is changed then switch it with previous
			switchScreenSafely();
			
			state->currentScreen->render();
		}
	}

	void endGame()
	{

	}
}