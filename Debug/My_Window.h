#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <fstream>
#include<sstream>
#include <map>

#include "config.h"
#include "Background.h"
#include "My_Button.h"
#include "Game_Board.h"
#include "Spaceship.h"
#include "Bullets.h"
#include "Enemies.h"
#include "Bonus.h"
#include "Player.h"

class My_Window : public Fl_Double_Window
{
	friend class Spaceship;
	friend class Bullet;
public:
	My_Window(int w, int h, const char *label);
	~My_Window(void);

	Background *_background;
	My_Button *_newgame, *_loadgame, *_instructions, *_highscores, *_authors, *_quit;
	My_Button  *_back_to_main_menu, *_exit_from_game, *_game_over;
	Fl_Box *_instructions_box, *_authors_box;
	Game_Board *_game_board;
	Spaceship *_ship1, *_ship2, *_ship3;
	Bullets *_bullets;
	Enemies *_enemies;
	Bonus *_bonus;
	Player *_player;
	Fl_Output *_xyShip, *_xyBonus, *_points, *_level, *_lives;

	static void newgame_cb(Fl_Widget *o, void* v); 
	static void loadgame_cb(Fl_Widget *o, void* v);
	static void instructions_cb(Fl_Widget *o, void* v); 
	
	static void authors_cb(Fl_Widget *o, void* v); 
	static void quit_cb(Fl_Widget *o, void* v);
	static void back_to_main_menu_cb(Fl_Widget *o, void* v); 
	static void exit_from_game_cb(Fl_Widget *o, void* v);
	static void game_over_cb(Fl_Widget *o, void* v);
};
