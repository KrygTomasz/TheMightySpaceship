#include <FL/Fl.H>
#include <math.h>
#include <string>
#include <sstream>
#include <ctime>
#include "My_Window.h"
#include <windows.h>

string intToChar(int w);
string pairIntToChar(int w1, int w2);

void callback(void *userdata) {
	My_Window *o = (My_Window*)userdata;
	if (!Player::pause)
	{

		if (Spaceship::slow_motion)
		{
			Sleep(100);
			Spaceship::slow_motion--;
		}

		
		o->_bullets->refresh();
		if (o->_bullets->bonusBullet2)
		{
			o->_ship1->space = 1;
			o->_bullets->bonusBullet2--;
		}
		if (o->_ship1->space)
		{
			if (o->_bullets->bonusBullet1)
			{
				o->_bullets->newBullets_bonus(o->_ship1->x + PIC_SIZE / 2 - BULLET_SIZE / 2, o->_ship1->y - BULLET_SIZE);
				o->_ship1->space = 0;
				o->_bullets->bonusBullet1--;
			}
			else
			{
				o->_bullets->newBullet(o->_ship1->x + PIC_SIZE / 2 - BULLET_SIZE / 2, o->_ship1->y - BULLET_SIZE, o->_ship1->angle);
				o->_ship1->space = 0;
			}
		}


		if (o->_ship1->u < FLOW && o->_ship1->u > 0)
		{
			o->_ship1->move(0, -ceil((FLOW - o->_ship1->u) / 30));
			o->_ship1->u++;
			if (o->_ship1->u == FLOW)
				o->_ship1->u = 0;
		}
		if (o->_ship1->d < FLOW && o->_ship1->d > 0)
		{
			o->_ship1->move(0, ceil((FLOW - o->_ship1->d) / 30));
			o->_ship1->d++;
			if (o->_ship1->d == FLOW)
				o->_ship1->d = 0;
		}
		if (o->_ship1->r < FLOW && o->_ship1->r > 0)
		{
			o->_ship1->move(ceil((FLOW - o->_ship1->r) / 30), 0);
			o->_ship1->r++;
			if (o->_ship1->r == FLOW)
				o->_ship1->r = 0;
		}
		if (o->_ship1->l < FLOW && o->_ship1->l > 0)
		{
			o->_ship1->move(-ceil((FLOW - o->_ship1->l) / 30), 0);
			o->_ship1->l++;
			if (o->_ship1->l == FLOW)
				o->_ship1->l = 0;
		}

	
		o->_enemies->refresh();
		o->_enemies->newEnemy();
		o->_enemies->hit(*o->_bullets);
		o->_enemies->collision(o->_ship1->x, o->_ship1->y);

		
		if (o->_bonus->visible())
			o->_bonus->collision(o->_ship1->x, o->_ship1->y, o->_enemies);

		o->_xyShip->value(pairIntToChar(o->_ship1->x, o->_ship1->y).c_str());
		o->_xyBonus->value(pairIntToChar(o->_bonus->x, o->_bonus->y).c_str());
		o->_points->value(intToChar(o->_player->points).c_str());
		o->_level->value(intToChar(o->_player->lvl).c_str());
		o->_lives->value(intToChar(o->_player->lives).c_str());


		if (o->_player->lives == 0)
		{
			o->_game_over->set_visible();
			Player::pause =true;
		}

	}
	o->redraw();
	Fl::repeat_timeout(1/60, callback, userdata);
}

void callbackBonusy(void *userdata)
{
	My_Window *o = (My_Window*)userdata;

	if (o->_bonus->visibleMine&&!Player::pause)
	{
		
			o->_bonus->newBonus();	
	}
	o->redraw();
	Fl::repeat_timeout(15, callbackBonusy, userdata);
}

int Player::points = 0;
int Player::lvl = 1;
int Player::lives = 3;
int Bullets::bonusBullet1 = 0;
int Bullets::bonusBullet2 = 0;
int Spaceship::slow_motion = 0;
bool Player::pause = false;
int  __stdcall WinMain(HINSTANCE a, HINSTANCE b, char* c, int d)
{
	srand(time(NULL));
	My_Window Window(WINDOWWIDTH, WINDOWHEIGHT, "The Mighty Spaceship");

	Fl::add_timeout(1/60, callback, &Window);
	Fl::add_timeout(15, callbackBonusy, &Window); 
	
	
	return Fl::run();
}


string intToChar(int w)
{
	ostringstream oss;
	oss << w;
	string strr;
	strr = oss.str();
	return strr;
}

string pairIntToChar(int w1, int w2)
{
	ostringstream oss1, oss2;
	oss1 << w1;
	oss2 << w2;
	string strr;
	strr = oss1.str() + " , " + oss2.str();
	return strr;
}
