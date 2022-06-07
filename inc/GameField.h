#ifndef GAMEFIELD_H
# define GAMEFIELD_H

# include <iostream>
# include <string>
# include <cassert>

# include <cstring>
# include <fstream>
# include <vector>

using namespace std;

class GameField
{
	private :
		int** field;
		int row_;
		int col_;

		void read_map(vector<string>& map);
	public :
		GameField(int row_size = 21, int col_size = 21);

		~GameField();

		GameField(const GameField& cp);

		int get_cell(int x, int y) const;

		void set_cell(int x, int y, int value);

		int get_row_size() const;

		int get_col_size() const;

		GameField& initializeField();
		GameField& operator= (const GameField& cp);
		
		friend GameField initializeField(const string& file_Name);
		friend ostream& operator<< (ostream& os, const GameField& gf);
};

ostream& operator<< (ostream& os, const GameField& gf);
GameField initializeField(const string& file_Name);

#endif
