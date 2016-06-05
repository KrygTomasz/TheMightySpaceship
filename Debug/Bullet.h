#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_PNG_Image.H>
#include <math.h>

class Bullet : public Fl_Widget
{
	friend class Spaceship;
	friend class My_Window;
public:
	Bullet(int X, int Y, double A, int V);
	~Bullet(void);
	void draw(void);
	void move_bullet(void);
	bool isOut(void);
	Fl_PNG_Image *bullet;
	int xb;
	int yb;
	double angle;
	int velocity;
};