#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<cmath>

#include "ConsoleGameEngine.h"
#include "PlayerHeader.h"

int main() {
	WindowEngine* window = new WindowEngine("WALKING GAME IN CONSOLE", 12, 10);
	PlayerPawn* player = new PlayerPawn(window);
	int max_walls = 3;
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
	std::cout << "\n\t\t>>>PRESS ANY KEY TO LEAVE A GAME<<<";
	while (true)
	{
		if (_kbhit()) {
			break;
		}
	}
	return 0;
}