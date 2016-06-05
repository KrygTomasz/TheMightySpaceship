#include "Enemies.h"
#include "Enemy.h"
#include "config.h"
#include<ctime>
#include<cmath>

Enemies::Enemies(void): Fl_Widget(BOARDWIDTH, BOARDHEIGHT, BOARD_X, BOARD_Y)
{
	visible = false;
	isSuperPresent = false;
	reset = false;
}
void Enemies::newEnemy(void)
{	
	static int i = 0;
	static int j = 0;
	if (reset)
	{
		i = 0;
		j = 0;
	}
	reset = false;
	static int number = (int)(floor(rand())) % 100 + 60;
	if ( visible )
	{
		i++;
		if (i == number)
		{
			enemies.push_back(new Enemy());
			i = 0;
			number = max(1, 40 - 3 * Player::lvl) + (int)(floor(rand())) % 150 / Player::lvl;
			if (!isSuperPresent)
				j++;
			if (j == 20+8*Player::lvl)
			{
				for (int k = 0; k < Player::lvl; k++)
				{
					makeRecentSpecial();
					isSuperPresent = true;
					j = 0;
				}
			}
		}
	}	
}

void Enemies::refresh(void)
{
	for (auto i = enemies.begin(); i != enemies.end();)
	{
		if (((*i)->isOut() && !(*i)->super) || (*i)->out == 1)
		{
			delete *i;
			i = enemies.erase(i);
		}
		else
		{
			(*i)->move();		
			i++;
		}
	}
}
void Enemies::hide()
{
	visible = false;	
}
void Enemies::clear()
{
	for (auto i = enemies.begin(); i != enemies.end();i++)
		delete *i;
	enemies.clear();
	reset = true;
	isSuperPresent = false;

}
void Enemies:: set_visible(void)
{
	visible = true;
	
}
void Enemies::draw(void)
{
	for (auto i = enemies.begin(); i != enemies.end(); i++)
		if(visible)
			(*i)->draw();
}

void Enemies::hit( Bullets &b )
{
	
	for (auto i = enemies.begin(); i != enemies.end(); i++)
	for (auto j = b.bullets.begin(); j != b.bullets.end();)
	{
		if (((*j)->xb - (*i)->x)<32 && ((*j)->xb - (*i)->x)>0 && ((*j)->yb - (*i)->y)<32 && ((*j)->yb - (*i)->y)>0)
		{
			((*i)->lives)--;
			if ((*i)->lives == 0)
			{
				(*i)->out = true;
				if ((*i)->super)
				{
					Player::points += 100;
					Player::lvl++;
					isSuperPresent = false;
				}
				else
					Player::points += 10;
			}
			delete *j;
			j = b.bullets.erase(j);
			break;
		}
		else
			j++;
	}
}

void Enemies::collision(int xb, int yb)
{
	for (auto i = enemies.begin(); i != enemies.end();)
	if ((xb - (*i)->x)<32 && (xb - (*i)->x)>-32 && (yb - (*i)->y)<32 && (yb - (*i)->y)>-32)
	{
		Player::lives -= 1;
		if ((*i)->super)
			isSuperPresent = false;
		delete *i;
		i=enemies.erase(i);
	}
	else i++;
}

void Enemies::makeRecentSpecial(void)
{
	if (enemies.begin() != enemies.end())
	{
	
		enemies.push_back(new Enemy());
		enemies.back()->enemy = new Fl_PNG_Image("enemy2.png");
		enemies.back()->super = true;
		enemies.back()->lives = 6+2*Player::lvl;
	}
}