#include "Enemy.h"
#include "config.h"
#include <ctime>
#include <cmath>
Enemy::Enemy(void) : Fl_Widget(BOARDWIDTH, BOARDHEIGHT, BOARD_X, BOARD_Y)
{
	enemy = new Fl_PNG_Image("enemy.png");
	out = 0;
	super = false;
	lives = 1;
	int start = rand() % 4;
	switch (start)
	{
	case 0:
		this->x = BOARD_X;
		this->y = BOARD_Y + rand() % (BOARDHEIGHT - BOARD_Y);
		vx = (rand() % 6 + 1) / 2.0;
		vy = (rand() % 6 + 1 / 2.0)*pow(-1, rand());
		break;
	case 1:
		this->x = BOARD_X + BOARDWIDTH;
		this->y = BOARD_Y + rand() % (BOARDHEIGHT - BOARD_Y);
		vx = -(rand() % 6 + 1) / 2.0;
		vy = (rand() % 6 + 1 / 2.0)*pow(-1, rand());
		break;
	case 2:
		this->x = BOARD_Y + rand() % (BOARDWIDTH - BOARD_X);
		this->y = BOARD_Y;
		vx = ((rand() % 6 + 1) / 2.0)*pow(-1, rand());
		vy = (rand() % 6 + 1 / 2.0);
		break;
	case 3:
		this->x = BOARD_Y + rand() % (BOARDWIDTH - BOARD_X);
		this->y = BOARD_Y + BOARDHEIGHT;
		vx = -(rand() % 6 + 1) / 2.0;
		vy = (rand() % 6 + 1 / 2.0)*pow(-1, rand());
		break;
	}
}
Enemy::~Enemy(void)
{
	delete enemy;
}
void Enemy::draw(void)
{
	fl_push_clip(BOARD_X, BOARD_Y, BOARDWIDTH, BOARDHEIGHT);
	enemy->draw((int) this->x,(int) this->y);
	fl_pop_clip();
}

void Enemy::move(void)
{
	if (super)
	{
		if (isOutLeft())
			vx = abs(vx);
		if (isOutRight())
			vx = -1 * abs(vx);
		if (isOutBottom())
			vy = -1 * abs(vy);
		if (isOutTop())
			vy = abs(vy);
	}
	x += vx;
	y += vy;
}

bool Enemy::isOut(void)
{
	if (x < BOARD_X-36)
		return true;
	if (x > BOARD_X + BOARDWIDTH)
		return true;
	if (y > BOARD_Y + BOARDHEIGHT)
		return true;
	if (y < BOARD_Y-36)
		return true;
	return false;
}
bool Enemy::isOutLeft(void)
{
	if (x < BOARD_X)
		return true;
	return false;
}
bool Enemy::isOutRight(void)
{
	if (x > BOARD_X + BOARDWIDTH - 36)
		return true;
	return false;
}
bool Enemy::isOutTop(void)
{
	if (y < BOARD_Y)
		return true;
	return false;
}
bool Enemy::isOutBottom(void)
{
	if (y > BOARD_Y + BOARDHEIGHT - 36)
		return true;
	return false;
}