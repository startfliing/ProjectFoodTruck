#include <stdio.h>
#include <tonc.h>
#include <tonc_tte.h>

#include "MenuState.hpp"

int main()
{
	// Init interrupts and VBlank irq.
	irq_init(NULL);
	irq_add(II_VBLANK, NULL);

	GameState* gs = new MenuState();
	while(1){
		GameState* temp = gs->run();
		gs = temp;
	}

	return 0;
}
