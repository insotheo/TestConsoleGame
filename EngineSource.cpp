#pragma once

#include "ConsoleGameEngine.h"

#include<Windows.h>
#include<iostream>

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

void WindowEngine::loose_frame() {
	isWork = false;
	std::system("cls");
	std::system("title YOU LOOSE!");
	std::system("color 4");
	std::cout << "\tYOU LOOSE\n";
}

void WindowEngine::win_frame() {
	isWork = false;
	std::system("cls");
	std::system("title YOU WIN!");
	std::system("color 2");
	std::cout << "\tYOU WON!\n";
}