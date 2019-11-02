#include <iostream>

using namespace std;

char whiteBoard[8][8], blackBoard[8][8];
char board[50][50];

int solveWhite(int startRow, int startColumn)
{
	int count = 0;

	for (int i = startRow; i < startRow + 8; i++)
	{
		for (int j = startColumn; j < startColumn + 8; j++)
		{
			if (board[i][j] != whiteBoard[i - startRow][j - startColumn]) count++;
		}
	}

	return count;
}

int solveBlack(int startRow, int startColumn)
{
	int count = 0;

	for (int i = startRow; i < startRow + 8; i++)
	{
		for (int j = startColumn; j < startColumn + 8; j++)
		{
			if (board[i][j] != blackBoard[i - startRow][j - startColumn]) count++;
		}
	}

	return count;
}

int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				whiteBoard[i][j] = 'W';
				blackBoard[i][j] = 'B';
			}
			else if ((i + j) % 2 == 1)
			{
				whiteBoard[i][j] = 'B';
				blackBoard[i][j] = 'W';
			}
		}
	}

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < m; j++)
		{
			board[i][j] = line.at(j);
		}
	}

	int minCount = 0;
	
	for (int i = 0; i < n - 8 + 1; i++)
	{
		for (int j = 0; j < m - 8 + 1; j++)
		{
			int whiteCount = solveWhite(i, j);
			int blackCount = solveBlack(i, j);

			if (i == 0 && j == 0)
			{
				minCount = (whiteCount < blackCount) ? whiteCount : blackCount;
			}
			else
			{
				int count = (whiteCount < blackCount) ? whiteCount : blackCount;
				if (count < minCount) minCount = count;
			}
		}
	}

	cout << minCount << "\n";

	return 0;
}
