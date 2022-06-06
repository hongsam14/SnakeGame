#include "GateGenerator.h"
#include "Gate.h"

static Point g_dir[8] = {Point(-1, 0), Point(-1, 1), Point(0, 1), Point(1, 1),
		Point(1, 0), Point(1, -1), Point(0, -1), Point(-1, -1)};

GateGenerator::GateGenerator(const GameField& field)
{
	GameField copy(field);

	for (int i = 0; i < copy.get_col_size(); i++)
	{
		for (int j = 0; j < copy.get_row_size(); j++)
		{
			search_wall(copy, Point(j, i));
		}
	}
	//init rand
	srand((unsigned int)time(NULL));
	//init gate pointer
	gate = NULL;
}

GateGenerator::~GateGenerator()
{
	if (gate != NULL)
		delete gate;
	wall_data.clear();
	vector<Point>().swap(wall_data);
}

void GateGenerator::generate_Gate(GameField& gf)
{
	static int p_num = 0;
	static int p_num_2 = 0;
	
	int r_num = rand() % wall_data.size() + 1;
	int r_num_2 = rand() % wall_data.size() + 1;
	
	while (r_num == r_num_2)
		r_num_2 = rand() % wall_data.size() + 1;
	//restore wall
	if (p_num && p_num_2)
	{
		Point p_point = wall_data[p_num];
		Point p_point_2 = wall_data[p_num_2];
		
		gf.set_cell(p_point.x, p_point.y, 1);
		gf.set_cell(p_point_2.x, p_point_2.y, 1);
	}
	//generate gate
	Point point = wall_data[r_num];
	Point point_2 = wall_data[r_num_2];
	
	gf.set_cell(point.x, point.y, 7);
	gf.set_cell(point_2.x, point_2.y, 7);

	gate = new Gate(gf, point, point_2);

	//save past data
	p_num = r_num;
	p_num_2 = r_num_2;
}

Gate& GateGenerator::getGate() const
{
	return *gate;
}

int GateGenerator::search_wall(GameField& field, const Point& sp)
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
