#include "MenuState.hpp"
#include "InGameState.hpp"

#include <tonc.h>
#include <stdio.h>
#include <tonc_tte.h>

extern int init_text();

MenuState::MenuState(){

}


//Important thing to consider:
//What are the endpoints from being InGame?
GameState* MenuState::run(){
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;

	init_text();
    int value = 0;
    int cursor = 0;
    while(!key_hit(KEY_A)){
        if(value % 60 == 0){ // the chars in #{} affect how print operates (i.e. 'es' allowed old text to be erased
			tte_printf("#{es;P:%d,%d}Menu", cursor, cursor);
            cursor++;
            value = 0;
		}
        value++;
        key_poll();
        VBlankIntrWait();
    }

    return new InGameState();
}