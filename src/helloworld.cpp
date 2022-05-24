#include <ncurses.h>
#include <iostream>
#include "map.h"
using namespace std;

int main(void)
{
	WINDOW *win1;
	int row, col;
	cin >> row >> col;
	int** map1 = makemap(row, col);
	map1 = initialMap(row, col);
	
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);

	attron(COLOR_PAIR(1));
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			printw("%d ", map1[i][j]);	
		}
		printw("\n");
	}
	
	attroff(COLOR_PAIR(1));
	refresh();
	getch();
	endwin();

	map1 = deleteMap();
	return 0;
}
