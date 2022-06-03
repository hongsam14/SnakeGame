#ifndef _WALL_
#define _WALL_

#include "Point.h"

class Wall
{
public:
    Wall(GameField &gf);
    ~Wall();
    vector<Point> wall_list;
};

#endif