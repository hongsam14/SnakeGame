#include "GameField.h"
#include "Screen.h"


static void game_view(const GameField& gf, Screen& sc)
{
	//print game field
	for (int y = 0; y < gf.get_col_size(); y++)
	{
		for (int x = 0; x < gf.get_row_size(); x++)
		{
			sc.print_cell(x, y, gf.get_cell(x, y));
		}
	}
	sc.update();
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
	//game view
	game_view(gf, sc);
	sc.update();
	getch();
	return 0;
}
