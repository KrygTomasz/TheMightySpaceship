#include "Player.h"
#include <fstream>
#include<time.h>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Draw.H>
#include <FL/fl_ask.H>


void Player::save(void)
{
	time_t now = time(0);
	struct tm tstruct;
	char fileName[80];
	tstruct = *localtime(&now);
	strftime(fileName, sizeof(fileName), "%Y-%m-%d.%X.game", &tstruct);
	for (int i = 0; fileName[i]!=0;i++)
	if (fileName[i] == ':')
		fileName[i] = '-';
	ofstream file(fileName);
	if (!file.is_open())
		return;
	file << Player::lvl << endl;
	file << Player::lives<<endl;
	file << Player::points << endl;
	file.close();
}
void Player::reset(void)
{
	Player::lvl = 1;
	Player::lives = 3;
	pause = false;
	Player::points = 0;
}
bool Player::load (void)
{
	Fl_Native_File_Chooser fnfc;
	fnfc.title("Load game");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("Game files\t*.game\n");
	fnfc.directory(".");
	switch (fnfc.show()) 
	{
	case -1:
		fl_alert("The file cannot be opened"); 
		return false;
	case 1:
		return false;
	default:
		ifstream file(fnfc.filename());
		if (!file.is_open())
		{
			fl_alert("The file cannot be opened");
			return false;
		}
		string line;
		getline(file, line);
		Player::lvl = atoi(line.c_str());
		getline(file, line);
		Player::lives=atoi(line.c_str());
		getline(file, line);
		Player::points = atoi(line.c_str());
		return true; 
	}
}
