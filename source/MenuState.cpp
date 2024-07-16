#include "tonc.h"
#include "MenuState.hpp"
#include "InGameState.hpp"

MenuState::MenuState(){

}


//Important thing to consider:
//What are the endpoints from being InGame?
GameState* MenuState::run(){
    while(!key_hit(KEY_A)){
        key_poll();
        VBlankIntrWait();
    }

    return new InGameState();
}