#include "GameField.h"
#include "Screen.h"
#include "Snake.h"
#include "Gate.h"

#include <thread>
#include <chrono>
#include <mutex>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define EXIT -1
#define FRAME_RATE 500

using std::thread;


static int g_command = 0;
static bool g_game_status = true;

static void game_control()
{
	//wait for first frame
	this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
	while (g_game_status)
	{
		int input(getch());
		switch(input)
		{
			case 260:
				g_command = LEFT;
				break;
			case 261:
				g_command = RIGHT;
				break;
			case 259:
				g_command = UP;
				break;
			case 258:
				g_command = DOWN;
				break;
			default:
				g_command = EXIT;
		}
		this_thread::yield();
	}
}

static void game_view(const GameField& gf, Screen& sc)
{
	sc.clear_Screen();
	sc.draw_Basic();
	for (int y = 0; y < gf.get_col_size(); y++)
	{
		for (int x = 0; x < gf.get_row_size(); x++)
			sc.print_cell(x, y, gf.get_cell(x, y));
	}
	sc.update();
}

static void game_collision(const GameField& gf, const Snake& snake)
{
}

static void game_Loop(GameField& gf, Screen& sc, Snake& snake, mutex& m, Gate& gate)
{
	//game view
	do
	{
		m.lock();
		//print gameField
		game_view(gf, sc);
		//collision check
		game_collision(gf, snake);
		//move Snake
		if (g_command != EXIT)
		{
			snake.getNextPoint(g_command);
			snake.update(gf, gate);
		}
		else
			g_game_status = false;
		//sleep
		this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
		m.unlock();
	}
	while (g_game_status);
}

int main(int argc, char** argv)
{
	//init GameField
	GameField gf;
	
	if (argc > 1)
		gf = initializeField(argv[1]);
	else if (argc == 1)
		gf.initializeField();
	else
	{
		cerr << "too many arguments!!"<<endl;
		return 1;
	}
	cout << gf << endl;
	
	//init Screen
	Screen sc("SnakeGame", '#', gf.get_row_size() * 3, gf.get_col_size() + 2);
	//init Snake
	Snake snake(gf);
	//init Gate
	Wall wall(gf);
	Gate gate(gf, wall);
	//thread control
	mutex m;
	thread control(game_control);
	control.detach();
	//game loop
	game_Loop(gf, sc, snake, m, gate);
	return 0;
}
