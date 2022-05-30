#include <ncurses.h>
#include <iostream>
#include "GameField.h"
#include "Snake.h"
using namespace std;

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

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

	snake.getNextPoint(UP);
	snake.update(gf);

	for(int i = 0; i < gf.get_col_size(); i++) {
		for(int j = 0; j < gf.get_row_size(); j++) {
			printw("%d ", gf.get_cell(j, i));	
		}
		printw("\n");
	}
	refresh();

	snake.getNextPoint(LEFT);
	snake.update(gf);

	snake.getNextPoint(DOWN);
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
