#ifndef GATE_GENERATOR_H
#define GATE_GENERATOR_H

#include "Point.h"
#include "GameField.h"
#include <vector>
//#include "Gate.h"

using namespace std;

class Gate_Generator
{
	public :
		Gate_Generator(const GameField& field);
		~Gate_Generator();
		//member func
		void generate_Gate();
	private :
		vector<Point> wall_data;
		int search_wall(GameField& field, const Point& sp);
};

#endif
