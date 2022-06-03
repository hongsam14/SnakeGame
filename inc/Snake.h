#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "Point.h"
#include "GameField.h"

class Snake
{
public:
    Snake(GameField& gf);
    ~Snake();
    void update(GameField& gf);
    
    Point getNextPoint(const int dir);
    Point getHeadPoint();
    int getSnakeLength();
    void getItem(GameField& gf);

private:
    Point priv_pos;
    Point next_pos;
    Point head_pos;
    vector<Point> bodies;
};

#endif