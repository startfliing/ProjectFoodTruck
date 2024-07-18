#include <stdio.h>
#include <tonc.h>
#include <tonc_tte.h>

#include "InGameState.hpp"
#include "BattleState.hpp"

extern int init_text();

/*

    Helper Functions

*/


/*

    Classes

*/

BattleState::BattleState(InGameState* igs){
	currentState = igs;
}



//Important thing to consider:
//What are the endpoints from being InGame?
GameState* BattleState::run(){

	// Video mode 0, enable bg 0.
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;

	init_text();
	int value = 0;
	int x = 70, y = 70;
	while(!key_hit(KEY_START))
	{
		key_poll();

		x += key_tri_horz();
		y += key_tri_vert();


		//only update the timer when the "clock ticks"
		// the chars in #{} affect how print operates (i.e. 'es' allowed old text to be erased)
		tte_printf("#{es;P:%d,%d}BattleState", x, y);


		VBlankIntrWait();
		value--;
	}

    return currentState;
}