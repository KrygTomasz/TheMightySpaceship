#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Button.H>

#include "config.h"

class My_Button : public Fl_Button
{
public:
	My_Button(int x, int y, int w, int h, const char *label);
};