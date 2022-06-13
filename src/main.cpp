#include "GameField.h"
#include "Screen.h"
#include "Snake.h"
#include "Gate.h"
#include "GateGenerator.h"

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


int g_command = 3;
static bool g_game_status = true;
int get_growthitem_counter = 0;
int get_poisonitem_counter = 0;
int pass_gate_counter = 0;


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

static bool game_check_collision(GameField& gf, Snake& snake, GateGenerator& gtr, int cmd)
{
	bool out;
	//Point p = snake.getNextPoint(cmd);
	snake.setDirection(cmd);
	Point p = snake.getNextPos();
	Point b;
	//judge
	switch(gf.get_cell(p.x, p.y))
	{
		case 1:
		case 2:
		case 4:
			return false;
		case 5: //Growth Item
			get_growthitem_counter++;
			snake.bodyPushback();
			break;
        case 6: //Decrease Item
			if(snake.getSnakeLength() > 3) {
				get_poisonitem_counter++;
				b = snake.getBodiesback();
				gf.set_cell(b.x, b.y, 0);
				snake.bodyPopback();
				break;
			} else {
				g_command = EXIT;
				break;
			}
				
		case 7:
			//gate
			//snake.warp(gtr.getGate());
		default :
			;
	}
	return true;
}

//static void game_Loop(GameField& gf, Screen& sc, Snake& snake, mutex& m, Gate& gate)
static void game_Loop(GameField& gf, Screen& sc, Snake& snake, GateGenerator& gtr, mutex& m)
{
	int frame = 0;
	bool coll_check = true;
	//game view
	do
	{
		m.lock();
		//print gameField
		game_view(gf, sc);
		//move Snake
		if (g_command == EXIT || coll_check == false)
			g_game_status = false;
		if (g_game_status)
		{
			//check collision
			coll_check = game_check_collision(gf, snake, gtr, g_command);
			//update data
			snake.update(gf, gtr.getGate());
		}
		frame++;
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
	GateGenerator gate_gtr(gf);
	//thread control
	mutex m;
	thread control(game_control);
	control.detach();
	//game loop
	gate_gtr.generate_Gate(gf);
	game_Loop(gf, sc, snake, gate_gtr, m);
	return 0;
}
