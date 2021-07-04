#include "CoreState.hpp"

void CoreState::setCurrentScreen(std::shared_ptr<Screen> newScreen)
{
	this->newScreen = newScreen;
	this->changeScreen = true;
}

void CoreState::exitGame()
{
	this->shouldExit = true;
}