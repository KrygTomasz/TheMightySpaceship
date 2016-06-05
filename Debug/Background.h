#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_PNG_Image.H>

class Background : public Fl_Widget
{
public:
	Background(int X, int Y, int W, int H);
	~Background(void);

	void draw(void);
private:
	Fl_PNG_Image *space;
};