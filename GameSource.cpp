#include<iostream>
#include<string>

#include "ConsoleGameEngine.h"

int main() {
	WindowEngine* window = new WindowEngine("TEST GAME", 15, 10);
	while (window->isWork)
	{

		window->draw_frame();
	}
}