#include <stdio.h>
#include <tonc.h>
#include <tonc_tte.h>

#include "InGameState.hpp"
#include "BattleState.hpp"
#include "SaveData.hpp"

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
	SaveData sd = loadSaveData();
	while(!key_hit(KEY_A))
	{
		key_poll();
		if(key_hit(KEY_UP) || key_hit(KEY_DOWN)){
			sd.y += key_tri_vert();
		}
		if(key_hit(KEY_RIGHT) || key_hit(KEY_LEFT)){
			sd.x += key_tri_horz();
		}
		
		//only update the timer when the "clock ticks"
		// the chars in #{} affect how print operates (i.e. 'es' allowed old text to be erased)
		tte_printf("#{es;P:%d,%d}(%d, %d)", sd.x, sd.y, sd.x, sd.y);

		if(key_hit(KEY_START)){
			saveSaveData(sd);
		}

		if(key_hit(KEY_SELECT)){
			sd.x = sd.y = 0;
			resetSaveData();
		}


		VBlankIntrWait();
	}

    return currentState;
}