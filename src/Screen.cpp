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

Screen::Screen(const string& Title, wchar_t c, int W, int H): title(Title), bc(c), w(W), h(H)
{
	setlocale(LC_ALL, "");
	//init screen
	initscr();
	resize_term(h, w);
	//init color
	start_color();
	init_color();
	//input setting
	keypad(stdscr, true);
	curs_set(0);
	noecho();
	draw_Basic();
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

void Screen::init_color()
{
	init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
	init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_RED);
	init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
}

void Screen::print_cell(int x, int y, int cell)
{
	int cp;
	
	switch (cell)
	{
		case 4 :
			cp = COLOR_PAIR(YELLOW);
			break;
		case 3 :
			cp = COLOR_PAIR(GREEN);
			break;
		case 2 :
		case 1 :
			cp = COLOR_PAIR(WHITE);
			break;
		case 0 :
		default :
			cp = COLOR_PAIR(BLACK);
	}
	
	attron(cp);
	mvprintw(y + 1, x + 1, "\u2B1B");
	attroff(cp);
}

int Screen::update()
{
	return refresh();
}
