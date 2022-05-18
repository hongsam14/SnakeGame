#ifndef GAMEFIELD_H
# define GAMEFIELD_H

# include <iostream>
# include <string>

# include <fstream>

using namespace std;

class GameField
{
	private :
		int** field;
		const int row_;
		const int col_;
	public :
		GameField(int row_size, int col_size);

		~GameField();

		GameField(const GameField &cp);

		int init_map(string file_name);

		int getCell(int x, int y) const;
		
		void setCell(int x, int y, int value);

		friend ostream& operator<< (ostream& os, const GameField& gf);
};

ostream& operator<< (ostream& os, const GameField& gf);

#endif
