#include "Point.h"

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

Point Point::moveTo(const int dir)
{
    int x = (*this).x;
    int y = (*this).y;

    switch (dir)
    {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case RIGHT:
            x++;
            break;
        case LEFT:
            x--;
            break;
    }
    return Point(x,y);
}

Point& Point::operator=(const Point& a)
{
    x = a.x;
    y = a.y;
    return(*this);
}

bool operator==(const Point& a, const Point& b)
{
    return (a.x == b.x) && (a.y == b.y);
}
std::ostream& operator<<(std::ostream& outStream, const Point& point)
{
    outStream << "(" << point.x << "," << point.y << ")" << '\n';
    return outStream;
}