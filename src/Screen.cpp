#include "Screen.h"

Window::Window(wchar_t c, int x, int y, int W, int H) : bc(c), w(W), h(H)
{
	win = newwin(h, w, y, x);
}

Window::~Window()
{
	delwin(win);
}

int Window::update()
{
	return wrefresh(win);
}

int Window::clear()
{
	return wclear(win);
}

void Window::draw_border()
{
	if (bc)
		if (wborder(win, bc, bc, bc, bc, bc, bc, bc, bc))
			cerr << "can't set border" << endl;
	mvwprintw(win, 0, 0, title.c_str());
}

int Window::print_num(int x, int y, int num)
{
	int d = 0;
	int o;

	if (!num)
		d = 1;
	else
	{
		for (int i = num; i; i /= 10)
			d++;
	}
	o = d;
	
	char * s;

	s = new char[d + 1];
	s[d--] = 0;
	for (int i = 0, t = pow(10, d); d >= 0; i++, t /= 10, d--)
	{
		s[i] = '0' + (num / t);
		num %= t; 
	}
	
	mvwprintw(win, y, x, s);
	delete[] s;
	return o;
}

GameBoard::GameBoard(wchar_t c, int x, int y, int W, int H) : Window(c, x, y, W, H)
{
	title = "GameBoard";
}


GameBoard::~GameBoard()
{
}

void GameBoard::print(int x, int y, int cell, int)
{
	int cp;
	
	switch (cell)
	{
		case 7 :
			cp = COLOR_PAIR(MAGENTA);
			break;
		case 6 :
			cp = COLOR_PAIR(RED);
			break;
		case 5 :
			cp = COLOR_PAIR(BLUE);
			break;
		case 4 :
			cp = COLOR_PAIR(YELLOW);
			break;
		case 3 :
			cp = COLOR_PAIR(GREEN);
			break;
		case 2 :
			cp = COLOR_PAIR(E_WHITE);
			break;
		case 1 :
			cp = COLOR_PAIR(WHITE);
			break;
		case 0 :
		default :
			cp = COLOR_PAIR(BLACK);
	}
	
	wattron(win, cp);
	mvwprintw(win, y + 1, x * 2 + 1, "\u2B1B");
	wattroff(win, cp);
}

ScoreBoard::ScoreBoard(wchar_t c, int x, int y, int W, int H) : Window(c, x, y, W, H)
{
	title = "ScoreBoard";
	max_len = 3;
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::printIdx()
{
	mvwprintw(win, 1, 2, "B:");
	mvwprintw(win, 2, 2, "+:");
	mvwprintw(win, 3, 2, "-:");
	mvwprintw(win, 4, 2, "G:");
}

void ScoreBoard::print(int d1, int d2, int d3, int d4)
{
	if (d1 > max_len)
		max_len = d1;
	int i = print_num(4, 1, d1);
	mvwprintw(win, 1, 4 + i + 1, "/");
	print_num(4 + i + 3, 1, max_len);
	
	print_num(4, 2, d2);
	print_num(4, 3, d3);
	print_num(4, 4, d4);
}

MissionBoard::MissionBoard(wchar_t c, int x, int y, int W, int H) : Window(c, x, y, W, H)
{
	title = "MissionBoard";
	b = 3;
	p = 0;
	m = 0;
	g = 0;
}

MissionBoard::~MissionBoard()
{
}

void MissionBoard::setMission(int b, int p, int m, int g)
{
	this->b = b;
	this->p = p;
	this->m = m;
	this->g = g;
}

void MissionBoard::printBool(int x, int y, int b)
{
	mvwprintw(win, y, x, "(");
	if (b)
		mvwprintw(win, y, x + 1, "V");
	mvwprintw(win, y, x + 2, ")");
}

void MissionBoard::printIdx()
{
	mvwprintw(win, 1, 2, "B:");
	mvwprintw(win, 2, 2, "+:");
	mvwprintw(win, 3, 2, "-:");
	mvwprintw(win, 4, 2, "G:");
}

void MissionBoard::print(int d1, int d2, int d3, int d4)
{
	int i;
	
	i = print_num(4, 1, b);
	printBool(4 + i + 1, 1, b <= d1);
	i = print_num(4, 2, p);
	printBool(4 + i + 1, 2, b <= d2);
	i = print_num(4, 3, m);
	printBool(4 + i + 1, 3, b <= d3);
	i = print_num(4, 4, g);
	printBool(4 + i + 1, 4, b <= d4);
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
	init_pair(E_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_RED);
	init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
}

int Screen::clear_Screen()
{
	return clear();
}

int Screen::update()
{
	return refresh();
}
