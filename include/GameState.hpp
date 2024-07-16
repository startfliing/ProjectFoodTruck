//GameState
//This is the main way to manage flow of the game
//the main file will essentially be a loop of GameState.run()
//which will return the new GameState that will activate.
//This should also also for things like a 'PauseState' which 
//can allow for a state to interrupt another temporarily.

#ifndef __GAME_STATE__
#define __GAME_STATE__

// Children
class IntroState;
class TitleState;
class MenuState;
class InGameState;

class GameState{
    public:
        GameState(){};
        virtual GameState* run() = 0;
};

#endif