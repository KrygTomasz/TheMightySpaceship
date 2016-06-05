#include "My_Button.h"

My_Button::My_Button(int x, int y, int w, int h, const char *label) : Fl_Button(x, y, w, h, label)
{
	this->box(FL_PLASTIC_DOWN_BOX);
	this->down_box(FL_PLASTIC_UP_BOX);
	this->color(FL_DARK_BLUE);
	this->color2(FL_DARK_BLUE);
	this->labelsize(20);
	this->labelfont(FL_BOLD);
	this->labelcolor(fl_rgb_color(15, 15, 100));
};