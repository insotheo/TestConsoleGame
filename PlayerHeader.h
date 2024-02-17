#pragma once

#include "GraphicsChars.h"
#include "ConsoleGameEngine.h"
#include "GameRandom.h"

enum PlayerVector {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
};

class PlayerPawn {
public:
	PlayerVector vector = PlayerVector::STOP;
	unsigned int posX = 0;
	unsigned int posY = 0;

	PlayerPawn(WindowEngine* window) {
		game_window = window;
		posX = get_random_coords(game_window->height, game_window->width).first;
		posY = get_random_coords(game_window->height, game_window->width).second;
		game_window->screen[posY][posX] = PLAYER_CHAR;
	}

	void make_finish_point();

private:
	WindowEngine* game_window;
};