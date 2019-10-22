#include <iostream>

using namespace std;

bool arr[2200][2200];

void init()
{
	for (int i = 0; i < 2200; i++)
	{
		for (int j = 0; j < 2200; j++)
		{
			arr[i][j] = false;
		}
	}
}

void solve(int x, int y, int n)
{
	if (n == 1)
	{
		arr[x][y] = true;
		return;
	}

	int divide = n / 3;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			solve(x + (i * divide), y + (j * divide), divide);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	solve(0, 0, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]) cout << "*";
			else cout << " ";
		}

		cout << endl;
	}

	return 0;
}
