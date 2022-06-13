#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "Point.h"
#include "GameField.h"
#include "Gate.h"
class Snake
{
public:
    Snake(GameField& gf);
    
    ~Snake();
    
    void update(GameField& gf, Gate& gate);
    
    void update(GameField& gf);
    
    Point getHeadPoint() const;
    
    int getSnakeLength() const;
    
    void getItem(GameField& gf);

    int getDirection() const;
    
    void warp(Gate& gate);

    void setDirection(int dir);

    Point getNextPos();

private:
    Point next_pos;
    Point head_pos;
    vector<Point> bodies;

    int dir;
};

#endif
