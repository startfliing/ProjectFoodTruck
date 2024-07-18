#ifndef __BATTLE_STATE__
#define __BATTLE_STATE__

#include "GameState.hpp"

class InGameState;

class BattleState : public GameState{
    public:
        BattleState(InGameState* igs);
        GameState* run();
    private:
        InGameState* currentState;
};

#endif