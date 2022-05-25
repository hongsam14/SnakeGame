#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <locale.h>
#include <string>

#include <cassert>
#include <iostream>

using namespace std;

class Window
{
	private :
		const wchar_t bc;
	protected :
		const int w, h;
		WINDOW *win;
	public :
		Window(wchar_t c, int x, int y, int W = 10, int H = 10);
		~Window();
		int update();
		virtual void print();
};

class Screen
{
	private :
		const int w, h;
		const string title;
		const wchar_t bc;

		void draw_Basic();

	public :
		Screen(const string& Title, wchar_t c, int W = 40 , int H = 40);
		~Screen();
		void print_cell(int x, int y, int cell);
		int update();
};

#endif
