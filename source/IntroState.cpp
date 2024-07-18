#include "IntroState.hpp"
#include "MenuState.hpp"

#include <tonc.h>
#include <stdio.h>
#include <tonc_tte.h>

extern int init_text();

IntroState::IntroState(){

}


//Important thing to consider:
//What are the endpoints from being InGame?
GameState* IntroState::run(){
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;

	init_text();
    int value = 0;
    int timer = 11;
    while(!key_hit(KEY_START) && timer > -1){
        if(value % 60 == 0){ // the chars in #{} affect how print operates (i.e. 'es' allowed old text to be erased
			timer--;
            tte_printf("#{es;P:120,70}Intro duration left = %d", timer);
            value = 0;
		}
        value++;
        key_poll();
        VBlankIntrWait();
    }
    //fade to black
    return new MenuState();
}