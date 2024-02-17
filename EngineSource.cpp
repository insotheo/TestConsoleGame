#pragma once

#include "ConsoleGameEngine.h"
#include "GameRandom.h"

#include<Windows.h>
#include<iostream>
#include<string.h>

void WindowEngine::draw_frame() {
	std::system("cls");
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (screen[y][x] == NULL) {
				screen[y][x] = EMPTY_CHAR;
			}
			std::cout << screen[y][x];
		}
		std::cout << "\n";
	}
	Sleep(FPS);
}

void WindowEngine::draw_frame(UI_Position ui_pos, const std::string ui_text) {
	std::system("cls");
	if (ui_pos == UI_Position::TOP) {
		std::cout << ui_text;
	}
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (screen[y][x] == NULL) {
				screen[y][x] = EMPTY_CHAR;
			}
			std::cout << screen[y][x];
		}
		std::cout << "\n";
	}
	if (ui_pos == UI_Position::BOTTOM) {
		std::cout << ui_text;
	}
	Sleep(FPS);
}

void WindowEngine::loose_frame() {
	std::system("cls");
	std::system("title YOU LOOSE!");
	std::system("color 4");
	std::cout << "\n\tYOU LOOSE\n";
	isWork = false;
}

void WindowEngine::win_frame() {
	std::system("cls");
	std::system("title YOU WIN!");
	std::system("color 2");
	std::cout << "\n\tYOU WON!\n";
	isWork = false;
}

void WindowEngine::make_briks(const int anum) {
	for (int b = 0; b < anum; ++b) {
		std::pair<int, int> pos = get_random_coords(height, width);
		if (screen[pos.second][pos.first] == EMPTY_CHAR) {
			screen[pos.second][pos.first] = WALL_CHAR;
		}
	}
}