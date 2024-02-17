#pragma once

#include "GameRandom.h"

std::pair<int, int> get_random_coords(int height, int width) {
	srand(time(nullptr));

	int randX = rand() % width;
	int randY = rand() % height;

	return std::make_pair(randX, randY);
}