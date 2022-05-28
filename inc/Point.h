#ifndef _POINT_
#define _POINT_

#include <iostream>

class Point
{
public:
    int x;
    int y;
    Point() :x(0), y(0) { };
    Point(int x, int y) :x(x), y(y) { };

    bool isValid();
    Point moveTO(const int x, const int y);

    friend bool operator==(const Point& x, const Point& y);
    Point& operator=(const Point& a);
    friend std::ostream& operator<<(std::ostream& outStream, const Point& point);
};

#endif