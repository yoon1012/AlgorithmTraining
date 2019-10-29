#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>>& board)
{
	for (vector<int> v : board)
	{
		for (int i : v)
		{
			if (i == 0) cout << ".";
			else if (i == 1) cout << "#";
		}

		cout << endl;
	}
}

const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}},
};

bool update(vector<vector<int>>& board, int row, int column, int type, int delta)
{
	bool result = true;

	for (int i = 0; i < 3; i++)
	{
		int nextRow = row + coverType[type][i][0];
		int nextColumn = column + coverType[type][i][1];

		if (nextRow < 0 || nextColumn < 0)
			result = false;
		else if (nextRow >= board.size() || nextColumn >= board[0].size())
			result = false;
		else if ((board[nextRow][nextColumn] += delta) > 1)
			result = false;
	}

	return result;
}

int cover(vector<vector<int>>& board)
{
	int row = -1, column = -1;

	for (int i = 0; i < board.size(); i++)
	{
		vector<int> line = board[i];

		for (int j = 0; j < line.size(); j++)
		{
			if (board[i][j] == 0)
			{
				row = i;
				column = j;
				break;
			}
		}

		if (row != -1) break;
	}

	if (row == -1 && column == -1) return 1;

	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (update(board, row, column, i, 1))
			count += cover(board);
		update(board, row, column, i, -1);
	}

	return count;
}

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int h, w;
		cin >> h >> w;

		vector<vector<int>> board;

		for (int j = 0; j < h; j++)
		{
			string lineString;
			cin >> lineString;

			vector<int> line;

			for (int k = 0; k < lineString.length(); k++)
			{
				if (lineString.at(k) == '#') line.push_back(1);
				else if (lineString.at(k) == '.') line.push_back(0);
			}

			board.push_back(line);
		}

		cout << cover(board) << endl;
	}

	return 0;
}
