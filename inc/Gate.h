#ifndef _GATE_
#define _GATE_

#include "/home/mumat/SnakeGame/inc/GameField.h"
#include "/home/mumat/SnakeGame/inc/Point.h"
#include <iostream>

class Gate
{
private:
    Point gate_pos1;
    Point gate_pos2;
public:
    Gate();
    ~Gate();
    
    bool check_wall();
    Point pass_gate();
    int entry_direction();
    //생성자에 진행 방향 담기.    
    friend bool operator==(const Point& x, const Point& y);
    Point& operator=(const Point& a);
    friend std::ostream& operator<<(std::ostream& outStream, const Point& point);

};

#endif