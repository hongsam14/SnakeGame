#include "GateGenerator.h"
#include <iostream>

static Point g_dir[8] = {Point(-1, 0), Point(-1, 1), Point(0, 1), Point(1, 1),
		Point(1, 0), Point(1, -1), Point(0, -1), Point(-1, -1)};

Gate_Generator::Gate_Generator(const GameField& field)
{
	GameField copy(field);

	for (int i = 0; i < copy.get_col_size(); i++)
	{
		for (int j = 0; j < copy.get_row_size(); j++)
		{
			search_wall(copy, Point(j, i));
		}
	}
}

Gate_Generator::~Gate_Generator()
{
	wall_data.clear();
	vector<Point>().swap(wall_data);
}

void Gate_Generator::generate_Gate()
{
}

int Gate_Generator::search_wall(GameField& field, const Point& sp)
{
	//check
	switch(field.get_cell(sp.x, sp.y))
	{
		case 1:
			wall_data.emplace_back(sp);
		case 2:
			field.set_cell(sp.x, sp.y, 8);
			break ;
		case 0:
		default:
			return 0;
	}
	
	Point m;
	
	for (int i = 0; i < 8; i++)
	{
		m = sp + g_dir[i];
		//skip
		if (!m.isValid(field))
			continue ;
		return search_wall(field, m);
	}
	return 1;
}
