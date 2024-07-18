#ifndef __INTRO_STATE__
#define __INTRO_STATE__

#include "GameState.hpp"

class IntroState : public GameState{
    public:
        IntroState();
        GameState* run();
};

#endif