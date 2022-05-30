#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "/home/mumat/SnakeGame/inc/Point.h"
#include "GameField.h"

class Snake
{
public:
    Snake(GameField& gf);

    void update(GameField& gf);
    Point getNextPoint(const int dir);
    int getSnakeLength();
    void getItem(GameField& gf);

private:
    Point priv_pos;
    Point next_pos;
    Point head_pos;
    vector<Point> bodies;
};

#endif