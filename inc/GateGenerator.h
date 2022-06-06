#ifndef GATE_GENERATOR_H
#define GATE_GENERATOR_H

#include "Point.h"
#include "GameField.h"

#include <vector>
#include <cstdlib>
#include <ctime>
//#include "Gate.h"

using namespace std;

class GateGenerator
{
	public :
		GateGenerator(const GameField& field);
		~GateGenerator();
		//member func
		void generate_Gate(GameField& gf);
	private :
		vector<Point> wall_data;
		int search_wall(GameField& field, const Point& sp);
};

#endif
