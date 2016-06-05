#pragma once

#include "Player.h"
#include "Bullets.h"
#include "Spaceship.h"
#include "Enemies.h"

#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Draw.H>

class Bonus : public Fl_Widget
{
	friend class My_Window;
public:
	
	Bonus(int W, int H);
	~Bonus(void);

	Fl_PNG_Image *bonus;
	void draw(void);
	void newBonus(void);
	void visibility(void);
	void collision(int x, int y, Enemies *e);

	bool visibleMine;

	int x, y;
	const char* FileName;
};