#ifndef _WALL_
#define _WALL_

#include "Point.h"

class Wall
{
private:
    vector<Point> wall_list;
public:
    Wall(GameField &gf);
    ~Wall();
};

#endif