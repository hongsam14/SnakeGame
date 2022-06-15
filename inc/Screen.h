#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <locale.h>
#include <string>

#include <cassert>
#include <iostream>
#include <cwchar>
#include <cmath>

using namespace std;

enum Color { WHITE=1, E_WHITE, BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, LAST };

class Window
{
	private :
		const wchar_t bc;
	protected :
		const int w, h;
		string title;
		WINDOW *win;

		int print_num(int x, int y, int num);
	public :
		Window(wchar_t c, int x, int y, int W = 10, int H = 10);
		virtual ~Window();
		int update();
		int clear();
		
		void draw_border();
		virtual void print(int, int, int, int) = 0;
};

class GameBoard final :public Window
{
	public :
		GameBoard(wchar_t c, int x, int y, int W = 42, int H = 42);
		~GameBoard() override;
		
		void print(int x, int y, int cell, int = 0);
};

class ScoreBoard final : public Window
{
	private :
		int max_len;
	public :
		ScoreBoard(wchar_t c, int x, int y, int W = 10, int H = 10);
		~ScoreBoard() override;
		void printIdx();
		void print(int d1, int d2, int d3, int d4) override;
};

class MissionBoard final : public Window
{
	private :
		int b;
		int p;
		int m;
		int g;
		void printBool(int x, int y, int b);
	public :
		MissionBoard(wchar_t c, int x, int y, int W = 10, int H = 10);
		~MissionBoard() override;
		void setMission(int b, int p, int m, int g);
		void printIdx();
		void print(int d1, int d2, int d3, int d4) override;
};

class Screen
{
	private :
		const int w, h;
		const string title;
		const wchar_t bc;

		void init_color();

	public :
		Screen(const string& Title, wchar_t c, int W = 40 , int H = 40);
		~Screen();
		void draw_Basic();
		int clear_Screen();
		int update();
};

#endif
