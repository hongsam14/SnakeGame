#include "Wall.h"

Wall::Wall(GameField& gf)
{
    for(int y = 0; y < gf.get_col_size; y++){
        for(int x = 0; x < gf.get_row_size; x++) {
            if(gf.get_cell(x, y) == 1) {
                wall_list.push_back(x,y);
            }
        }
    }
}

Wall::~Wall()
{
    wall_list.clear();
    vector <Point>().swap(wall_list);
}