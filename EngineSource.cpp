#pragma once

#include "ConsoleGameEngine.h"

#include<Windows.h>
#include<iostream>

void WindowEngine::draw_frame() {
	std::system("cls");
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			std::cout << screen[y][x];
		}
		std::cout << "\n";
	}
	Sleep(FPS);
}