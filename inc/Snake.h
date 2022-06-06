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
    
    Point getNextPoint(const int dir);
    Point getHeadPoint() const;
    int getSnakeLength() const;
    void getItem(GameField& gf);
private:
    Point next_pos;
    Point head_pos;
    vector<Point> bodies;
};

#endif
