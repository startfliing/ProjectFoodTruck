#include <stdio.h>
#include <tonc.h>
#include <tonc_tte.h>

#include "IntroState.hpp"

int main()
{
	// Init interrupts and VBlank irq.
	irq_init(NULL);
	irq_add(II_VBLANK, NULL);

	GameState* gs = new IntroState();
	while(1){
		GameState* temp = gs->run();
		gs = temp;
		key_poll();
	}

	return 0;
}
