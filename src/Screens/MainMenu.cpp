#include "MainMenu.hpp"
#include "raylib.h"
#include "../Singletons/CoreState.hpp"

void MainMenu::render()
{
	CoreState* state = CoreState::getInstance();

	if (IsKeyPressed(KEY_ESCAPE))
	{
		state->exitGame();
	}

	BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}