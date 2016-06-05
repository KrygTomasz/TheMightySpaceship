#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_PNG_Image.H>
#include "Bullet.h"
#include <list>
#include <FL/fl_ask.H>

class Spaceship : public Fl_Widget
{
	friend class My_Window;
	friend class Bullet;
public:
	Spaceship(int X, int Y, int W, int H, const char *C, int v);
	~Spaceship(void);
	int handle(int);
	void draw(void);
	void move(int vx, int vy);
	void Spaceship::icon(double angle);
	Fl_PNG_Image *spaceship;
	int x;
	int y;
	double u, d, r, l, angle;
	int space;
	int velocity;

	static int slow_motion;
	
};