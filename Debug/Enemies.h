#pragma once
#include<list>
#include"Enemy.h"
#include"Player.h"
#include"Bullets.h"

#include <FL/Fl_Draw.H>

using namespace std;

class Enemies : public Fl_Widget
{
	friend class My_Window;
	friend class Enemy;

public:
	Enemies(void);
	void clear(void);
	void newEnemy(void);
	void refresh(void);
	void hide();
	void draw(void);
	void set_visible(void);
	void hit(Bullets &b);
	void makeRecentSpecial();
	void collision(int xb, int yb);
	
private:
	list <Enemy*> enemies;
	bool visible;
	bool isSuperPresent;
	bool reset;
};