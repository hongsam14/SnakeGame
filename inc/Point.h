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
    Point moveTo(const int dir);

    friend bool operator==(const Point& x, const Point& y);
    Point& operator=(const Point& a);
    
    Point& operator+= (const Point& a);
    friend Point operator+ (Point p1, const Point& p2);
    Point& operator-= (const Point& a);
    friend Point operator+ (Point p1, const Point& p2);
    friend Point operator- (Point p1, const Point& p2);

    friend std::ostream& operator<<(std::ostream& outStream, const Point& point);
};

Point operator+ (Point p1, const Point& p2);
Point operator- (Point p1, const Point& p2);

#endif
