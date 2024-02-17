#pragma once

#include<iostream>
#include<cstdlib>

#include "PlayerHeader.h"

void PlayerPawn::make_finish_point() {
	std::pair<int, int> coords = get_random_coords(game_window->height, game_window->width);
	unsigned int finX = coords.first;
	unsigned int finY = coords.second;
	if (finX == posX && finY == posY) {
		finX = finY = 5;
	}
	game_window->screen[finY][finX] = FINISH_CHAR;
}