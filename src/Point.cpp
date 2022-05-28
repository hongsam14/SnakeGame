#include "Point.h"


bool isValid();
Point moveTO(const int x, const int y);

Point& operator=(const Point& a);
bool operator==(const Point& x, const Point& y);
friend std::ostream& operator<<(std::ostream& outStream, const Point& point);