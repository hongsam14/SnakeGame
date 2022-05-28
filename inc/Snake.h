#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "GameField.h"

class Snake
{
public:
    Snake();

    void update();
    void getNextPoint();
    void getSnakeLength();

private:
    void next_pos;
    void head_pos;
    void bodies;
};

#endif