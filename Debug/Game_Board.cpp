#include "Game_Board.h"
#include "config.h"

Game_Board::Game_Board(int x, int y, int w, int h) : Fl_Widget(x, y, w, h) {
	gameboard = new Fl_PNG_Image("game_board.png");
}

Game_Board::~Game_Board(void)
{
	delete gameboard;
}

void Game_Board::draw(void)
{
	fl_push_clip(BOARD_X, BOARD_Y, BOARDWIDTH, BOARDHEIGHT);
	gameboard->draw(10, 10);
	fl_pop_clip();
}