#include <ncurses.h>
#include <iostream>
#include "GameField.h"
#include "/home/mumat/SnakeGame/inc/Snake.h"
using namespace std;

int main(int argc, char** argv)
{
#if 1
	GameField gf;
	gf.initializeField();
#else
	GameField gf;
	gf = initializeField("sample.map");
#endif
	Snake snake(gf);

	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);

	attron(COLOR_PAIR(1));
	for(int i = 0; i < gf.get_col_size(); i++) {
		for(int j = 0; j < gf.get_row_size(); j++) {
			printw("%d ", gf.get_cell(j, i));	
		}
		printw("\n");
	}
	attroff(COLOR_PAIR(1));
	refresh();

	snake.getNextPoint(0);
	snake.update(gf);

	for(int i = 0; i < gf.get_col_size(); i++) {
		for(int j = 0; j < gf.get_row_size(); j++) {
			printw("%d ", gf.get_cell(j, i));	
		}
		printw("\n");
	}
	refresh();
	getch();
	endwin();
	return 0;
}
