#include "Bonus.h"
#include "config.h"

#include <time.h>


const char* bonuses[7] = { "bonusPkt.png", "bonusKil.png", "bonusHeart.png", "bonusBullet.png", "bonus5.png", "bonus6.png", "bonus7.png" };


Bonus::Bonus(int W, int H) : Fl_Widget(x, y, W, H, FileName)
{
	srand(time(NULL));
	FileName = bonuses[rand()%7];
	bonus = new Fl_PNG_Image(FileName);
	this->x = rand() % (BOARDWIDTH-20) + BOARD_X;
	this->y = rand() % (BOARDHEIGHT-20) + BOARD_Y;
	visibleMine = false;
}

Bonus::~Bonus(void)
{
	delete bonus;
}

void Bonus::draw(void)
{
	fl_push_clip(BOARD_X, BOARD_Y, BOARDWIDTH, BOARDHEIGHT);
	bonus->draw(this->x, this->y);
	fl_pop_clip();
}

void Bonus::newBonus(void)
{
	srand(time(NULL)+this->x+this->y);
	this->FileName = bonuses[rand() % 7];
	bonus = new Fl_PNG_Image(FileName);
	this->x = rand() % (BOARDWIDTH-20) + BOARD_X;
	this->y = rand() % (BOARDHEIGHT-20) + BOARD_Y;

	this->set_visible();
}

void Bonus::visibility(void)
{
	visibleMine = true;
}

void Bonus::collision( int xs, int ys, Enemies *e)
{
	if ((abs(xs - this->x+BONUS_SIZE/2) < PIC_SIZE) && (abs(ys - this->y+BONUS_SIZE/2) < PIC_SIZE))
	{
		this->hide();
		if (FileName == bonuses[0])
			Player::points += 5;
		else if (FileName == bonuses[1])
			Player::lives -= 1;
		else if (FileName == bonuses[2])
			Player::lives += 1;
		else if (FileName == bonuses[3])
			Bullets::bonusBullet1 = 100;
		else if (FileName == bonuses[4])
			Bullets::bonusBullet2 = 1000;
		else if (FileName == bonuses[5])
			Spaceship::slow_motion = 60;
		else if (FileName == bonuses[6])
			e->clear();
	}
}