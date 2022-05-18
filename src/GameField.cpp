#include "GameField.h"

GameField::GameField(int row_size, int col_size) : row_(row_size), col_(col_size)
{
	field = new int*[col_];
	for (int i = 0; i < col_; i++)
		field[i] = new int[row_];
}

GameField::~GameField()
{
	for (int i = 0; i < col_; i++)
		delete[] field[i];
	delete[] field;
}

GameField::GameField(const GameField &cp) : row_(cp.row_), col_(cp.col_)
{
	field = new int*[col_];
	for (int i = 0; i < col_; i++)
	{
		field[i] = new int[row_];
		for (int j = 0; j < row_; j++)
			field[i][j] = cp.field[i][j];
	}
}

int GameField::init_map(string file_name)
{
	string line;
	ifstream file(file_name);
	
	if (!file.is_open())
		return 0;
	for (int i = 0; i < col_; i++)
	{
		if (!getline(file, line))
			return 0;
		for (int j = 0; j < row_; j++)
			field[i][j] = line[j] - '0';
	}
	file.close();
	return 1;
}

int GameField::getCell(int x, int y) const
{
	return field[y][x];
}

void GameField::setCell(int x, int y, int value)
{
	field[y][x] = value;
}

ostream& operator<< (ostream& os, const GameField& gf)
{
	for (int i = 0; i < gf.col_; i++)
	{
		for (int j = 0; j < gf.row_; j++)
			os << gf.field[i][j];
		os << endl;
	}
	return os;
}
