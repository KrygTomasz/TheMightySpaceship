#pragma once

#include <string>
#include <FL/fl_ask.H>
#include <FL/Fl.H>

using namespace std;

class Player
{
public:
	Player(void);

	static void reset(void);
	void gameOver(void);
	static bool load(void);
	static void save(void);
	static int points;
	static int lvl;
	static int lives;
	static bool pause;
};