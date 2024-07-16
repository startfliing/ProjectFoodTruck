#include <stdio.h>
#include <tonc.h>
#include <tonc_tte.h>

#include "InGameState.hpp"
#include "MenuState.hpp"

/*

    Helper Functions

*/

void init_text(){
	// Init 4bpp vwf text on bg 0.
	tte_init_chr4c(0, 			// BG 0
		BG_CBB(0)|BG_SBB(31),	// Charblock 0; screenblock 31
		0xF000,					// Screen-entry offset
		bytes2word(1,2,0,0),	// Color attributes.
		CLR_YELLOW, 			// Yellow text
		&verdana9Font,			// Verdana 9 font
		NULL					// Use default chr4 renderer
		);

	// Initialize use of stdio.
	tte_init_con();
}


/*

    Classes

*/

InGameState::InGameState(){

}



//Important thing to consider:
//What are the endpoints from being InGame?
GameState* InGameState::run(){

	// Video mode 0, enable bg 0.
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;

	init_text();
	
	int value = 180 * 60; //180 seconds * 60 frames
	while(value > 0 && !key_hit(KEY_START))
	{
		//only update the timer when the "clock ticks"
		if(value % 60 == 0){ // the chars in #{} affect how print operates (i.e. 'es' allowed old text to be erased)
			tte_printf("#{es;P:180,0}Timer = %d", value/60);
		}
		VBlankIntrWait();
        key_poll();
		value--;
	}

    return new MenuState();
}