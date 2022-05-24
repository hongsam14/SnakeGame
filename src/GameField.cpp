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

int GameField::get_cell(int x, int y) const
{
	return field[y][x];
}

void GameField::set_cell(int x, int y, int value)
{
	field[y][x] = value;
}

int GameField::get_row_size() const
{
	return row_;
}

int GameField::get_col_size() const
{
	return col_;
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

void GameField::read_map(vector<string>& map)
{
	for (int i = 0; i < col_; ++i)
	{
		for (int j = 0; j < row_; ++j)
		{
			if (strchr("01234", map[i][j]))
				field[i][j] = map[i][j] - '0';
			else
				field[i][j] = -1;
		}
	}
}

GameField generate_field(const string& file_name)
{
	string line;
	ifstream file(file_name);

	vector<string> tmp;
	int size_w(0);
	int size_h(0);

	//open and read mapfile
	assert(file.is_open());
	while (getline(file, line))
	{
		if (line.length() > size_w)
			size_w = line.length();
		tmp.emplace_back(line);
		size_h++;
	}
	//make GameField
	GameField gf(size_w, size_h);
	//write field
	gf.read_map(tmp);
	//clean
	tmp.clear();
	vector<string>().swap(tmp);
	file.close();
	return gf;
}
