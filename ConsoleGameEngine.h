#pragma once

#include<string>
#include<vector>
#include<iostream>

#include "GraphicsChars.h"

#define PIXEL_WIDTH_K 2 

#define FPS 60

enum UI_Position {
	TOP,
	BOTTOM
};

class WindowEngine {
public:
	std::string window_title;
	char** screen;
	unsigned int width;
	unsigned int height;
	bool isWork = true;

	WindowEngine(std::string TITLE, const unsigned int WIDTH, const unsigned int HEIGHT) {
		window_title = TITLE;
		height = HEIGHT;
		width = WIDTH * PIXEL_WIDTH_K;
		screen = new char* [height];
		for (int i = 0; i < height; ++i) {
			screen[i] = new char[width];
			for (int j = 0; j < width; ++j) {
				screen[i][j] = EMPTY_CHAR;
			}
		}
		std::system(("title " + window_title).c_str());
		isWork = true;
	}

	~WindowEngine()
	{
		isWork = false;
		for (int i = 0; i < height; ++i) {
			delete[] screen[i];
		}
		delete[] screen;
	}

	void draw_frame();

	void draw_frame(UI_Position ui_pos, const std::string ui_text);

	void win_frame();

	void loose_frame();

	void make_briks(const int anum);
};