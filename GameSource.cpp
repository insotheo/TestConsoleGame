#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<cmath>

#include "ConsoleGameEngine.h"
#include "PlayerHeader.h"

#define PRINT_ANIM_SPEED 10

void print_with_anim(std::string text) {
	for (char symb : text) {
		std::cout << symb;
		Sleep(PRINT_ANIM_SPEED);
	}
}

int main() {
	int max_walls, height, width;
	print_with_anim("Welcome to this console game...\nEnter the height of the field...\n");
	std::cin >> height;
	print_with_anim("Well... Now enter the width of the field...\n");
	std::cin >> width;
	print_with_anim("And now enter how fast will walls spanw...\n");
	std::cin >> max_walls;
	WindowEngine* window = new WindowEngine("WALKING GAME IN CONSOLE", width, height);
	PlayerPawn* player = new PlayerPawn(window);
	player->make_finish_point();
	while (window->isWork)
	{
		player->read_input();
		player->move();
		window->make_briks(max_walls);
		window->draw_frame(UI_Position::BOTTOM, ("MIND OUT! Your speed is " + std::to_string(player->speed) + " points!"));
	}
	Beep(900, 500);
	std::system("cls");
	print_with_anim("\n\t\t>>>PRESS ANY KEY TO LEAVE A GAME<<<");
	while (true)
	{
		if (_kbhit()) {
			break;
		}
	}
	return 0;
}