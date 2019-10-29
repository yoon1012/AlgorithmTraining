#include <iostream>
#include <vector>

using namespace std;

const int dColumn[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dRow[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

char board[5][5];

bool isValid(int row, int column)
{
	if (row < 0 || row >= 5) return false;
	else if (column < 0 || column >= 5) return false;

	return true;
}

bool search(int row, int column, const string& word)
{
	if (!isValid(row, column)) return false;
	if (board[row][column] != word[0]) return false;
	if (word.size() == 1) return true;

	for (int i = 0; i < 8; i++)
	{
		int nextRow = row + dRow[i];
		int nextColumn = column + dColumn[i];

		if (search(nextRow, nextColumn, word.substr(1))) return true;
	}

	return false;
}

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < 5; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < 5; j++) board[i][j] = line.at(j);
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		bool result;

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				result = search(j, k, word);

				if (result)
				{
					cout << word << " " << "YES" << endl;
					j = 6; k = 6;
				}
			}
		}

		if (!result) cout << word << " " << "NO" << endl;
	}

	return 0;
}
