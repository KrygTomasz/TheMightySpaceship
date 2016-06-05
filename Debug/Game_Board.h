#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_PNG_Image.H>

class Game_Board : public Fl_Widget
{
public:
	Game_Board(int x, int y, int w, int h);
	~Game_Board(void);
	void draw(void);
private:
	Fl_PNG_Image *gameboard;
};