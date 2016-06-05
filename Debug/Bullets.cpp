#include "Bullets.h"
#include "Bullet.h"
#include "config.h"
#include<ctime>
#include<cmath>
Bullets::Bullets(void) : Fl_Widget(BOARDWIDTH, BOARDHEIGHT, BOARD_X, BOARD_Y, "bullet.png")
{
	visible = false;
}
void Bullets::newBullet(int x, int y, double angle)
{
	bullets.push_back(new Bullet(x, y, angle, 1));
}

void Bullets::newBullets_bonus(int x, int y)
{
	for (int i = 0; i < 8; i++)
		bullets.push_back(new Bullet(x, y, i*0.25, 1));
}

void Bullets::refresh(void)
{
	for (auto i = bullets.begin(); i != bullets.end();)
	{
		if ((*i)->isOut())
		{
			delete *i;
			i = bullets.erase(i);
		}
		else
		{
			(*i)->move_bullet();
			i++;
		}
	}
}

void Bullets::hide()
{
	visible = false;
}
void Bullets::clear()
{
	for (auto i = bullets.begin(); i != bullets.end(); i++)
		delete *i;
	bullets.clear();

}
void Bullets::set_visible(void)
{
	visible = true;

}
void Bullets::draw(void)
{
	for (auto i = bullets.begin(); i != bullets.end(); i++)
		if (visible)
			(*i)->draw();
}