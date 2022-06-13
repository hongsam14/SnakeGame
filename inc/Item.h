#ifndef _ITEM_
#define _ITEM_

#include "Point.h"
#include <thread>
#include <chrono>

using namespace std;


class Item
{
private:
    Point growthItem;
    Point poisonItem;

    vector<Point> zero_map;
    int item_Num = 0;
public:
    Item(GameField& gf);
    ~Item();

    void generate_Item(GameField& gf);
};

#endif
