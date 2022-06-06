#ifndef _GATE_
#define _GATE_

#include <ctime>
#include <cstdlib>

#include "Wall.h"

using namespace std;

// UP 0
// DOWN 1
// RIGHT 2
// LEFT 3

class Gate
{
private:
    Point gate1, gate2;
    int gate_num;
    int gate_dir;
    int gate1Arr[4], gate2Arr[4];
public:
    bool passing_snake = false;
    pair<Point, Point> gates;
    Gate(GameField &gf, Wall &wall);
    ~Gate();

    void deleteGate(GameField &gf);
    int entryDirection(const int dir);
    Point findExitRoute(GameField &gf);
    
};

#endif