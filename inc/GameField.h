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
		const int row_;
		const int col_;

		void read_map(vector<string>& map);
	public :
		GameField(int row_size, int col_size);

		~GameField();

		GameField(const GameField& cp);

		int get_cell(int x, int y) const;
		
		void set_cell(int x, int y, int value);

		int get_row_size() const;

		int get_col_size() const;

		friend ostream& operator<< (ostream& os, const GameField& gf);
		friend GameField generate_field(const string& file_name);
};

ostream& operator<< (ostream& os, const GameField& gf);
GameField generate_field(const string& file_name);

#endif
