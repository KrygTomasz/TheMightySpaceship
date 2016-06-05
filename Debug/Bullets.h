#pragma once
#include<list>
#include"Bullet.h"
#include"Player.h"

#include <FL/Fl_Draw.H>

using namespace std;

class Bullets : public Fl_Widget
{
	friend class My_Window;
	friend class Bullet;
	friend class Enemies;
public:
	Bullets(void);
	void clear(void);
	void newBullet(int x, int y, double angle);
	void newBullets_bonus(int x, int y);
	void refresh(void);
	void hide();
	void draw(void);
	void set_visible(void);

	static int bonusBullet1;
	static int bonusBullet2;

private:
	list <Bullet*> bullets;
	bool visible;
};