#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

#include "ConsoleGameEngine.h"
#include "PlayerHeader.h"

int main() {
	WindowEngine* window = new WindowEngine("WALKING GAME IN CONSOLE", 25, 15);
	PlayerPawn* player = new PlayerPawn(window);
	player->make_finish_point();
	while (window->isWork)
	{
		
		window->draw_frame();
	}
	std::cout << "GAME OVER!\n";
}