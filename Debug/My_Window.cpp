#include "My_Window.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>



My_Window::My_Window(int w, int h, const char *label) : Fl_Double_Window(w, h, label)
{
	_background = new Background(0, 0, WINDOWWIDTH, WINDOWHEIGHT);
	_game_board = new Game_Board(BOARD_X, BOARD_Y, BOARDWIDTH, BOARDHEIGHT);
	_game_board->hide();
	_ship1 = new Spaceship((BOARDWIDTH / 2) - 32 / 2 + 10, (BOARDHEIGHT)-0.1*BOARDHEIGHT, BOARDWIDTH, BOARDHEIGHT, "ship50.png", 1);
	_ship1->hide();
	_bullets = new Bullets();
	_bullets->hide();
	_enemies = new Enemies();
	_enemies->hide();
	_bonus = new Bonus(BOARDWIDTH, BOARDHEIGHT);
	_bonus->hide();

	_newgame = new My_Button(300, 80, 200, 40, "New game");
	_newgame->callback(newgame_cb);
	_loadgame = new My_Button(300, 130, 200, 40, "Load Game");
	_loadgame->callback(loadgame_cb);
	_instructions = new My_Button(300, 180, 200, 40, "Instructions");
	_instructions->callback(instructions_cb);
	_authors = new My_Button(300, 230, 200, 40, "Authors");
	_authors->callback(authors_cb);
	_quit = new My_Button(300, 280, 200, 40, "Quit");
	_quit->callback(quit_cb);

	_back_to_main_menu = new My_Button(300, 330, 200, 40, "Back");
	_back_to_main_menu->callback(back_to_main_menu_cb);
	_back_to_main_menu->hide();
	_exit_from_game = new My_Button(605, 500, 180, 40, "Back to menu");
	_exit_from_game->callback(back_to_main_menu_cb);
	_exit_from_game->hide();
	_game_over = new My_Button(200, 300, 150, 50, "Game Over");
	_game_over->callback(game_over_cb);
	_game_over->hide();

	_xyShip = new Fl_Output(640, 50, 80, 40, "Ship: ");
	_xyShip->hide();
	_xyBonus = new Fl_Output(640, 100, 80, 40, "Bonus: ");
	_xyBonus->hide();
	_points = new Fl_Output(640, 150, 80, 40, "Points: ");
	_points->hide();
	_level = new Fl_Output(640, 200, 80, 40, "Level: ");
	_level->hide();
	_lives = new Fl_Output(640, 250, 80, 40, "Lives: ");
	_lives->hide();

	_instructions_box = new Fl_Box(250, 80, 300, 100, "The only aim of this game is to destroy comets and aliens\nwith your MIGHTY SPACESHIP!!!\nWhen your live is equal 0, you are dead.\nArrows - move\n'a', 'd' - rotate\n's' - shoot\n'q' - save");
	_instructions_box->labelcolor(FL_WHITE);
	_instructions_box->labelsize(26);
	_instructions_box->labeltype(FL_SHADOW_LABEL);
	_instructions_box->hide();


	_authors_box = new Fl_Box(350, 100, 100, 100, "Authors: \n\n Karolina Chrzaszcz \n Szymon Gornioczek \n Tomasz Kryg \n Michal Wolszleger");
	_authors_box->labelcolor(FL_WHITE);
	_authors_box->labelsize(26);
	_authors_box->labeltype(FL_SHADOW_LABEL);
	_authors_box->hide();

	end(); 
	show(); 
}

My_Window::~My_Window(void)
{
	delete _newgame;
	delete _loadgame;
	delete _instructions;
	delete _authors;
	delete _quit;
	delete _background;
	delete _back_to_main_menu;
	delete _exit_from_game;
	delete _instructions_box;
	delete _authors_box;
	delete _game_board;
	delete _ship1;
	delete _bonus;
	delete _player;
	delete _game_over;
	delete _bullets;
	delete _enemies;
	delete _xyShip;
	delete _xyBonus;
	delete _points;
	delete _level;
	delete _lives;
}

void My_Window::newgame_cb(Fl_Widget *o, void* v)
{
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();
	okno->_newgame->hide();
	okno->_loadgame->hide();
	okno->_instructions->hide();
	okno->_authors->hide();
	okno->_quit->hide();
	Player::reset();
	okno->_ship1->x = (BOARDWIDTH / 2) - 32 / 2 + 10;
	okno->_ship1->y = (BOARDHEIGHT)-0.1*BOARDHEIGHT;
	okno->_ship1->angle = 0.5;

	okno->_back_to_main_menu->hide();
	okno->_background->hide();

	okno->_xyShip->set_visible();
	okno->_xyBonus->set_visible();
	okno->_points->set_visible();
	okno->_level->set_visible();
	okno->_lives->set_visible();

	okno->_game_board->set_visible();
	okno->_ship1->set_visible();
	okno->_bullets->clear();
	okno->_bullets->set_visible();
	okno->_enemies->clear();
	okno->_enemies->set_visible();
	okno->_bonus->visibility();
	okno->_bonus->set_visible();
	okno->_exit_from_game->set_visible();
	okno->redraw();
}

void My_Window::loadgame_cb(Fl_Widget *o, void* v)
{
	
	if (!Player::load())
		return;
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();


	okno->_newgame->hide();
	okno->_loadgame->hide();
	okno->_instructions->hide();
	okno->_authors->hide();
	okno->_quit->hide();
	okno->_ship1->x = (BOARDWIDTH / 2) - 32 / 2 + 10;
	okno->_ship1->y = (BOARDHEIGHT)-0.1*BOARDHEIGHT;

	okno->_back_to_main_menu->hide();
	okno->_background->hide();

	okno->_xyShip->set_visible();
	okno->_xyBonus->set_visible();
	okno->_points->set_visible();
	okno->_level->set_visible();
	okno->_lives->set_visible();

	okno->_game_board->set_visible();
	okno->_ship1->set_visible();
	okno->_bullets->clear();
	okno->_bullets->set_visible();
	okno->_enemies->clear();
	okno->_enemies->set_visible();
	okno->_bonus->visibility();
	okno->_bonus->set_visible();
	okno->_exit_from_game->set_visible();
	okno->redraw();
}

void My_Window::instructions_cb(Fl_Widget *o, void* v)
{
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();

	okno->_newgame->hide();
	okno->_loadgame->hide();
	okno->_instructions->hide();
	okno->_authors->hide();
	okno->_quit->hide();

	okno->_instructions_box->set_visible();
	okno->_back_to_main_menu->set_visible();

	okno->redraw();
}


void My_Window::authors_cb(Fl_Widget *o, void* v)
{
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();

	okno->_newgame->hide();
	okno->_loadgame->hide();
	okno->_instructions->hide();
	okno->_authors->hide();
	okno->_quit->hide();

	okno->_authors_box->set_visible();
	okno->_back_to_main_menu->set_visible();

	okno->redraw();
}

void My_Window::quit_cb(Fl_Widget *o, void* v)
{
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();

	okno->_newgame->hide();
	okno->_loadgame->hide();
	okno->_instructions->hide();
	okno->_authors->hide();
	okno->_quit->hide();

	okno->hide();
}

void My_Window::game_over_cb(Fl_Widget *o, void* v)
{
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();

	Player::lives = 3;
	Player::lvl = 0;
	Player::points = 0;

	okno->_bonus->hide();
	okno->_bonus->visibleMine = false;
	okno->_instructions_box->hide();
	okno->_authors_box->hide();
	okno->_game_board->hide();
	okno->_ship1->hide();
	okno->_back_to_main_menu->hide();
	okno->_game_over->hide();
	okno->_enemies->hide();
	okno->_bullets->hide();
	okno->_exit_from_game->hide();
	okno->_xyShip->hide();
	okno->_xyBonus->hide();
	okno->_points->hide();
	okno->_level->hide();
	okno->_lives->hide();

	okno->_background->set_visible();
	okno->_newgame->set_visible();
	okno->_loadgame->set_visible();
	okno->_instructions->set_visible();
	okno->_authors->set_visible();
	okno->_quit->set_visible();

	okno->redraw();
}

void My_Window::back_to_main_menu_cb(Fl_Widget *o, void* v)
{
	My_Window *okno = (My_Window*)((Fl_Button*)o)->parent();


	okno->_bonus->hide();
	okno->_bonus->visibleMine = false;
	okno->_instructions_box->hide();
	okno->_authors_box->hide();
	okno->_game_board->hide();
	okno->_ship1->hide();
	okno->_back_to_main_menu->hide();
	okno->_enemies->hide();
	okno->_bullets->hide();
	okno->_exit_from_game->hide();
	okno->_xyShip->hide();
	okno->_xyBonus->hide();
	okno->_points->hide();
	okno->_level->hide();
	okno->_lives->hide();
	okno->_game_over->hide();

	okno->_background->set_visible();
	okno->_newgame->set_visible();
	okno->_loadgame->set_visible();
	okno->_instructions->set_visible();
	okno->_authors->set_visible();
	okno->_quit->set_visible();

	okno->redraw();
}


