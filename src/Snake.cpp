#include "Snake.h"
#include "Gate.h"

Snake::Snake(GameField& gf)
{
    head_pos.x = gf.get_row_size() / 2;
    head_pos.y = gf.get_col_size() / 2;
    bodies.push_back(Point(head_pos.x, head_pos.y));
    bodies.push_back(Point(head_pos.x + 1, head_pos.y));
    bodies.push_back(Point(head_pos.x + 2, head_pos.y));

    gf.set_cell(bodies[0].x, bodies[0].y, 3);
    for(int i = 1; i < bodies.size(); i++){
        gf.set_cell(bodies[i].x, bodies[i].y, 4);
    }
    //init dir
    dir = 0;
}

Snake::~Snake()
{
    bodies.clear();
    vector <Point>().swap(bodies);
}

Point Snake::getHeadPoint() const
{
    return head_pos;
}

int Snake::getSnakeLength() const
{
    return this->bodies.size();
}

void Snake::update(GameField& gf, Gate& gate)
{
    head_pos = next_pos;
    bodies.insert(bodies.begin(), head_pos);
    int len = bodies.size();
    gf.set_cell(bodies[len - 1].x, bodies[len - 1].y, 0);
    bodies.pop_back();
    if(head_pos == gate.gates.first){
        int nextDir = gate.gate_directions.second[1];
        g_command = nextDir;
        bodies[0] = gate.gates.second.moveTo(g_command);
        next_pos = bodies[0];
        head_pos = next_pos;
        gate.passing_snake = true;
    } else if(head_pos == gate.gates.second) {
        int nextDir = gate.gate_directions.first[1];
        g_command = nextDir;
        bodies[0] = gate.gates.first.moveTo(g_command);
        next_pos = bodies[0];
        head_pos = next_pos;
        gate.passing_snake = true;
    }
    gf.set_cell(bodies[0].x, bodies[0].y, 3);
    for(int i = 1; i < bodies.size(); i++){
        gf.set_cell(bodies[i].x, bodies[i].y, 4);
    }
}

void Snake::warp(Gate& gate)
{
	if (next_pos == gate.gates.first)
	{
		g_command = gate.gate_directions.second[1];
		next_pos = gate.gates.second.moveTo(g_command);
		gate.passing_snake = true;
	}
	else if (next_pos == gate.gates.second)
	{
		g_command = gate.gate_directions.first[1];
		next_pos = gate.gates.first.moveTo(g_command);
		gate.passing_snake = true;
	}
}

void Snake::update(GameField& gf)
{
    head_pos = next_pos;
    bodies.insert(bodies.begin(), head_pos);
    int len = bodies.size();
    gf.set_cell(bodies[len - 1].x, bodies[len - 1].y, 0);
    bodies.pop_back();
    gf.set_cell(bodies[0].x, bodies[0].y, 3);
    for(int i = 1; i < bodies.size(); i++){
        gf.set_cell(bodies[i].x, bodies[i].y, 4);
    }
}

void Snake::getItem(GameField& gf)
{
    head_pos = next_pos;
    switch (gf.get_cell(head_pos.x, head_pos.y))
    {
        case 5: //Growth Item
            bodies.push_back(bodies.back());
            break;
        case 6: //Decrease Item
            bodies.pop_back();
            break;
        case 0: //Passing map
            break;
    }
}
//add
int Snake::getDirection() const
{
	return dir;
}

void Snake::setDirection(int dir)
{
	this->dir = dir;
}

Point Snake::getNextPos()
{
    next_pos = head_pos.moveTo(dir);
    return next_pos;
}
