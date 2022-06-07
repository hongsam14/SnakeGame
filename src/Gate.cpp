#include "Gate.h"

Gate::Gate(GameField &gf, const Point& gate1, const Point& gate2)
{
	gates = make_pair(gate1, gate2);
	gate_directions = make_pair(findExitRoute(gf, gate1), findExitRoute(gf, gate2));
}

Gate::~Gate()
{   
    if(passing_snake == false)
        gate_num--;
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
