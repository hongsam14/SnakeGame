#include "Gate.h"

Gate::Gate(GameField &gf, Wall &wall)
{
    int gate_num = 0;
    int gate_dir = 0;
    int gate1Num, gate2Num;
    Point gate1, gate2;

    while(gate_num < 1){
        srand((unsigned int)time(NULL));
        
        gate1Num = (rand() % wall.wall_list.size()) + 1;
        gate2Num = (rand() % wall.wall_list.size()) + 1;
        gate1 = wall.wall_list[gate1Num];
        gate2 = wall.wall_list[gate2Num];
        
        gate_num++;
    }

    gates = make_pair(gate1, gate2);
    gate_directions = make_pair(findExitRoute(gf, gate1), findExitRoute(gf, gate2));
    gf.set_cell(gate1.x, gate1.y, 7);
    gf.set_cell(gate2.x, gate2.y, 7);

}

Gate::~Gate()
{   
    if(passing_snake == false)
        gate_num--;
}

void Gate::deleteGate(GameField &gf)
{
    if(passing_snake == false){
        gf.set_cell(gate1.x, gate1.y, 1);
        gf.set_cell(gate2.x, gate2.y, 1);
    }
        
}

vector<int> Gate::findExitRoute(GameField& gf, Point gate)
{
    vector<int> exitDir;
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Point exit = gate.moveTo(dirTable[i][j]);
            if(exit.isValid(gf) && gf.get_cell(exit.x, exit.y) == 0){
                exitDir.push_back(dirTable[i][j]);
                break;
            }
        }
    }
    return exitDir;
}
    