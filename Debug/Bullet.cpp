#include "Bullet.h"
#include "config.h"

Bullet::Bullet(int X, int Y, double A, int V) : Fl_Widget(X, Y, A, V)
{
	bullet = new Fl_PNG_Image("bullet.png");
	this->xb = X;
	this->yb = Y+PIC_SIZE/2;
	this->angle = A;
	this->velocity = V;
}
Bullet::~Bullet(void)
{
	delete bullet;
}
void Bullet::draw(void)
{
	fl_push_clip(BOARD_X, BOARD_Y, BOARDWIDTH, BOARDHEIGHT);
	bullet->draw(this->xb, this->yb);
	fl_pop_clip();
}

void Bullet::move_bullet(void)
{
	this->xb=this->xb+(int)(10*cos(PI*(this->angle)));
	this->yb=this->yb-(int)(10*sin(PI*(this->angle)));
}

bool Bullet::isOut(void)
{
	if (xb < BOARD_X)
		return true;
	if (xb > BOARD_X + BOARDWIDTH)
		return true;
	if (yb > BOARD_Y + BOARDHEIGHT)
		return true;
	if (yb < BOARD_Y)
		return true;
	return false;
}