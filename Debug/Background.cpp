#include "Background.h"

Background::Background(int X, int Y, int W, int H) : Fl_Widget(X, Y, W, H)
{
	space = new Fl_PNG_Image("space.png");
}

Background::~Background(void)
{
	delete space;
}

void Background::draw(void)
{
	space->draw(0, 0);
}