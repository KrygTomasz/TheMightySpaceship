#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_PNG_Image.H>

class Enemy : public Fl_Widget
{
	friend class My_Window;
	friend class Enemies;
public:
	Enemy(void);
	~Enemy(void);
	void move(void);
	void draw(void);
	bool isOut(void);
	bool isOutBottom(void);
	bool isOutTop(void);
	bool isOutLeft(void);
	bool isOutRight(void);
private:
	Fl_PNG_Image *enemy;
	double x;
	double y;
	double vx;
	double vy;
	bool super;
	bool out;
	int lives;


};