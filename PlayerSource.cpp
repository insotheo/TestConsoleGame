#pragma once

#include<iostream>
#include<cstdlib>
#include<conio.h>

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

void PlayerPawn::read_input() {
	if (_kbhit()) {
		char key = _getch();
		switch (key)
		{
		case 27: //ESC
			game_window->isWork = false;
			break;

		case 'W':
		case 'w':
			vector = PlayerVector::UP;
			break;

		case 'A':
		case 'a':
			vector = PlayerVector::LEFT;
			break;

		case 'S':
		case 's':
			vector = PlayerVector::DOWN;
			break;

		case 'D':
		case 'd':
			vector = PlayerVector::RIGHT;
			break;

		default:
			break;
		}
	}
}

void PlayerPawn::move() {
	int nextY, nextX;
	switch (vector)
	{
	case UP:
		nextY = posY - speed;
		nextX = posX;
		break;
	case DOWN:
		nextY = posY + speed;
		nextX = posX;
		break;
	case LEFT:
		nextY = posY;
		nextX = posX - speed;
		break;
	case RIGHT:
		nextY = posY;
		nextX = posX + speed;
		break;
	case STOP:
		nextY = posY;
		nextX = posX;
		break;
	}
	if (nextY < game_window->height && nextY >= 0 && nextX < game_window->width && nextX >= 0) {
		game_window->screen[posY][posX] = EMPTY_CHAR;
		if (game_window->screen[nextY][nextX] == EMPTY_CHAR) {
			posY = nextY;
			posX = nextX;
			game_window->screen[posY][posX] = PLAYER_CHAR;
		}
		else if (game_window->screen[nextY][nextX] == WALL_CHAR) {
			game_window->loose_frame();
		}
		else if (game_window->screen[nextY][nextX] == FINISH_CHAR) {
			game_window->win_frame();
		}
	}
	else {
		game_window->loose_frame();
	}
	vector = PlayerVector::STOP;

}