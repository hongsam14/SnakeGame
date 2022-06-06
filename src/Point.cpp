#include "Point.h"
#include "GameField.h"

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

bool Point::isValid()
{
    return (*this).x >= 0 && (*this).y >= 0 && (*this).x < 21 && (*this).y < 21;
}
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

Point& Point::operator+= (const Point& a)
{
	x += a.x;
	y += a.y;
	return *this;
}

Point& Point::operator-= (const Point& a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}

Point operator+ (Point p1, const Point& p2)
{
	p1 += p2;
	return p1;
}

Point operator- (Point p1, const Point& p2)
{
	p1 -= p2;
	return p1;
}

std::ostream& operator<<(std::ostream& outStream, const Point& point)
{
    outStream << "(" << point.x << "," << point.y << ")" << '\n';
    return outStream;
}
