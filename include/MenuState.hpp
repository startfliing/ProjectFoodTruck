#ifndef __MENU_STATE__
#define __MENU_STATE__

#include "GameState.hpp"

class MenuState : public GameState{
    public:
        MenuState();
        GameState* run();
};

#endif