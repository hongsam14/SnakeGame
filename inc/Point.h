#ifndef _POINT_
#define _POINT_

#include "/home/mumat/SnakeGame/inc/GameField.h"
#include <iostream>

class Point
{
public:
    int x;
    int y;
    Point() :x(0), y(0) { };
    Point(int x, int y) :x(x), y(y) { };

    bool isValid();
    Point moveTo(const int dir);
    //헤드 포인트 반환하는 함수 만들기.

    friend bool operator==(const Point& x, const Point& y);
    Point& operator=(const Point& a);
    friend std::ostream& operator<<(std::ostream& outStream, const Point& point);

};

#endif