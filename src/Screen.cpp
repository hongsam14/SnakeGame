#include "Screen.h"

Window::Window(wchar_t c, int x, int y, int W, int H) : bc(c), w(W), h(H)
{
	win = newwin(h, w, y, x);
	//draw border
	if (bc)
	{
		if (wborder(win, bc, bc, bc, bc, bc, bc, bc, bc))
			cerr << "can't set border" << endl;
	}
}

Window::~Window()
{
	delwin(win);
}

int Window::update()
{
	return wrefresh(win);
}

void Window::print()
{
}

/**
 *Screen
 **/

Screen::Screen(const string& Title, wchar_t c, int W, int H): title(Title), bc(c), w(W), h(H)
{
	setlocale(LC_ALL, "");
	//init screen
	initscr();
	resize_term(h, w);
	//init color
	//input setting
	keypad(stdscr, true);
	curs_set(0);
	noecho();
	//print title	
	draw_Basic();
	update();
}

Screen::~Screen()
{
	endwin();
}

void Screen::draw_Basic()
{
	//border
	if (border(bc, bc, bc, bc, bc, bc, bc, bc))
		cerr << "can't set border" << endl;
	//title
	mvprintw(0, (w - title.length()) / 2, title.c_str());
}

void Screen::print_cell(int x, int y, int cell)
{
	if (cell > 0)
		mvprintw(y + 1, x + 1, "\u2B1B");
	else
		mvprintw(y + 1, x + 1, "\u2B1C");
}

int Screen::update()
{
	return refresh();
}
