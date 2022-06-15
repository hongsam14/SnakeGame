#ifndef _ITEM_
#define _ITEM_

#include "Point.h"

using namespace std;

class Item
{
private:
    Point growthItem;
    Point poisonItem;

    vector<Point> zero_map;
public:
    Item(GameField& gf);
    ~Item();

    void generate_Item(GameField& gf);
};

#endif
