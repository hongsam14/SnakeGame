#include "Item.h"

Item::Item(GameField& gf)
{
    for (int i = 0; i < gf.get_col_size(); i++)
    {
        for (int j = 0; j < gf.get_row_size(); j++)
        {
            if(gf.get_cell(j, i) == 0) 
            {
                zero_map.push_back(Point(j, i));
            }
        }
    }
    //init rand
    srand((unsigned int)time(NULL));
}

Item::~Item()
{
    
	zero_map.clear();
	vector<Point>().swap(zero_map);
}

void Item::generate_Item(GameField& gf)
{
    
    static int p_num = 0;
    static int p_num2 = 0;


    int r_num = rand() % zero_map.size() + 1;
    int r_num2 = rand() % zero_map.size() + 1;

    while (r_num == r_num2)
        r_num2 = rand() % zero_map.size() + 1;

    if(p_num && p_num2)
    {
        Point p_point = zero_map[p_num];
		Point p_point_2 = zero_map[p_num2];
		
		gf.set_cell(p_point.x, p_point.y, 0);
		gf.set_cell(p_point_2.x, p_point_2.y, 0);
    }

    growthItem = zero_map[r_num];
    poisonItem = zero_map[r_num2];

    gf.set_cell(growthItem.x, growthItem.y, 5);
    gf.set_cell(poisonItem.x, poisonItem.y, 6);

    p_num = r_num;
    p_num2 = r_num2;

}