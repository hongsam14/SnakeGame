#include "Snake.h"

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

}
Snake::~Snake()
{
    bodies.clear();
    vector <Point>().swap(bodies);
    cout << bodies.capacity() << "\n";
}

Point Snake::getNextPoint(const int dir)
{
    next_pos = head_pos.moveTo(dir);
    return next_pos;
}

int Snake::getSnakeLength()
{
    return this->bodies.size();
}

void Snake::update(GameField& gf)
{
    priv_pos = head_pos;
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