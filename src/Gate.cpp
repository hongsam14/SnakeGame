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
        
        gates = make_pair(gate1, gate2);
        cout << gates.first;
        gate_num++;
    }
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

int Gate::entryDirection(const int dir)
{
    gate_dir = dir
    return gate_dir;
}

Point Gate::findExitRoute(GameField &gf)
{
    if(gf.get_cell(x, y) == 0) //진입 방향 cell이 0이면
        return gf.get_cell(x, y); //그 좌표 반환 후 head_ptr 설정해주기
    
    else if(gf.get_cell(x, y) == 0) //진입 방향 시계방향 cell이 0이면
        return gf.get_cell(x, y); //그 좌표 반환 후 head_ptr 설정해주기
    
    else if(gf.get_cell(x, y) == 0) //진입 방향 반시계방향 cell이 0이면
        return gf.get_cell(x, y); //그 좌표 반환 후 head_ptr 설정해주기
    
    else if(gf.get_cell(x, y) == 0) //진입 방향 반대방향이 0이면
        return gf.get_cell(x, y); //그 좌표 반환 후 head_ptr 설정해주기
}