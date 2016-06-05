#include "Spaceship.h"
#include "config.h"
#include "Player.h"

Spaceship::Spaceship(int X, int Y, int W, int H, const char *C, int v) : Fl_Widget(X, Y, W, H, C)
{
	spaceship = new Fl_PNG_Image(C);
	this->x = X;
	this->y = Y;
	this->u = 0;
	this->d = 0;
	this->r = 0;
	this->l = 0;
	this->velocity = v;
	
	this->angle = .5;
}

Spaceship::~Spaceship(void)
{
	delete spaceship;
}

int Spaceship::handle(int e)
{
	int r = Fl::event();
	if (r == FL_SHORTCUT)
	{ 
		int k = Fl::event_key();
		switch (k)
		{
		case 'p':
		{
					Player::pause = true;
					break;
		}
		case 'o':
		{
					Player::pause = false;
					break;
		}

		case FL_Up:
		{

					  if (!Player::pause)
					  {

						  if (y > BOARD_Y && y - velocity > BOARD_Y)
						  {
							  this->u = 1;
							  this->y = this->y - this->velocity;
						  }
						  else this->y = BOARD_Y;
					  }
					  break;
		}
			
		case FL_Down:
		{
						if (!Player::pause)
						{

							this->d = 1;
							if (y < BOARDHEIGHT - PIC_SIZE + BOARD_Y && y + velocity < BOARDHEIGHT - PIC_SIZE + BOARD_Y) this->y = this->y + this->velocity;
							else this->y = BOARDHEIGHT - PIC_SIZE + 10;
						}
						break;
		}
		
		case FL_Left:
		{
						if (!Player::pause)
						{

							this->l = 1;
							if (x > BOARD_X && x - velocity > BOARD_X) this->x = this->x - this->velocity;
							else this->x = BOARD_X;
						
						}
						break;
		}

		case FL_Right:
		{
						 if (!Player::pause)
						 {

							 this->r = 1;
							 if (x < BOARDWIDTH - PIC_SIZE + BOARD_X && x + velocity < BOARDWIDTH - PIC_SIZE + BOARD_X) this->x = this->x + this->velocity;
							 else this->x = BOARDWIDTH - PIC_SIZE + 10;
							
						 }
						 break;
		}
	
		case 'q':
		{
					Player::save();
					break;
		}
		case 'a':
		{
					
					if (!Player::pause)
					{
						this->angle = fmod(this->angle + 0.0625, 2);

						icon((this->angle));
					}
					break;
		}
		case 'd':
		{
					if (!Player::pause)
					{

						this->angle = fmod(this->angle + (2 - 0.0625), 2);

						icon((this->angle));
					}
					break;
		}
		case 's':
		{
					if (!Player::pause)
						space++;
		}
			return 1;
		}
	}
	return 0;
}

void Spaceship::draw(void)
{
	fl_push_clip(BOARD_X, BOARD_Y, BOARDWIDTH, BOARDHEIGHT);
	spaceship->draw(this->x, this->y);
	fl_pop_clip();
}

void Spaceship::move(int vx, int vy)
{
	if (y < BOARD_Y || y - velocity < BOARD_Y)
		this->y = BOARD_Y;
	else if (y > BOARDHEIGHT - PIC_SIZE + BOARD_Y || y + velocity > BOARDHEIGHT - PIC_SIZE + BOARD_Y)
		this->y = BOARDHEIGHT - PIC_SIZE + 10;
	else
		this->y = this->y + vy;
	if (x < BOARD_X || x - velocity < BOARD_X)
		this->x = BOARD_X;
	else if (x > BOARDWIDTH - PIC_SIZE + BOARD_X || x + velocity > BOARDWIDTH - PIC_SIZE + BOARD_X)
		this->x = BOARDWIDTH - PIC_SIZE + 10;
	else
		this->x = this->x + vx;
}

void Spaceship::icon(double angle)
{
	switch ((int)(angle * 100))
	{
	case 0:
	{
			  this->spaceship = new Fl_PNG_Image("ship0.png");
			  break;
	}
	case 25:
	{
			   this->spaceship = new Fl_PNG_Image("ship25.png");
			   break;
	}
	case 50:
	{
			   this->spaceship = new Fl_PNG_Image("ship50.png");
			   break;
	}
	case 75:
	{
			   this->spaceship = new Fl_PNG_Image("ship75.png");
			   break;
	}
	case 100:
	{
				this->spaceship = new Fl_PNG_Image("ship100.png");
				break;
	}
	case 125:
	{
				this->spaceship = new Fl_PNG_Image("ship125.png");
				break;
	}
	case 150:
	{
				this->spaceship = new Fl_PNG_Image("ship150.png");
				break;
	}
	case 175:
	{
				this->spaceship = new Fl_PNG_Image("ship175.png");
				break;
	}

	}

}