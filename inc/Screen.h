#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen
{
	private :
		int w, h;

	public :
		Screen(int W = 21, int H = 21) : w(W), h(H)
		{
			initscr();
			resize_term(w, h);
		}

};

#endif
