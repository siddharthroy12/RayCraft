#ifndef CORESTATE_HPP
#define CORESTATE_HPP

#include "../Screen/Screen.hpp"
#include <memory>


class CoreState
{
    public:
        static CoreState* getInstance()
        {
            static CoreState instance; // Guaranteed to be destroyed.
            return &instance; // Instantiated on first use.
        }
        
        CoreState(CoreState* const) = delete;
        CoreState* operator = (const CoreState* ) = delete;
    
    private:
        CoreState() {}
        ~CoreState() {}

    public:
        std::shared_ptr<Screen> currentScreen;
        bool changeScreen = false;
        std::shared_ptr<Screen> newScreen;

        void setCurrentScreen(std::shared_ptr<Screen> newScreen);

        bool shouldExit = false;
        void exitGame();
};

#endif