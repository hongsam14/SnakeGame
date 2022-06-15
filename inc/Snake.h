#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "Point.h"
#include "GameField.h"
#include "Gate.h"

extern int pass_gate_counter;

class Snake
{
public:
    Snake(GameField& gf);
    
    ~Snake();
    
    void update(GameField& gf);
    
    Point getHeadPoint() const;
    
    int getSnakeLength() const;
    
    int getDirection() const;

    void setDirection(int dir);

    void bodyPushback();

    void bodyPopback();
    
    Point getNextPos();

    Point getBodiesback();

    void warp(Gate& gate);
    
private:
    Point next_pos;
    Point head_pos;
    vector<Point> bodies;    

    int dir;
};

#endif
