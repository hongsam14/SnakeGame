#include "Point.h"

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

Point Point::moveTo(const int dir)
{
    int x_ = (*this).x;
    int y_ = (*this).y;

    switch (dir)
    {
        case UP:
            y_--;
            break;
        case DOWN:
            y_++;
            break;
        case RIGHT:
            x_++;
            break;
        case LEFT:
            x_--;
            break;
    }
    return Point(x_,y_);
}

bool Point::isValid(GameField& gf)
{
    return (*this).x >= 0 && (*this).y >= 0 && (*this).x < gf.get_row_size() && (*this).y < gf.get_col_size();
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
