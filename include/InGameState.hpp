#ifndef __IN_GAME_STATE__
#define __IN_GAME_STATE__

#include "GameState.hpp"

class InGameState : public GameState{
    public:
        InGameState();
        GameState* run();
};

#endif