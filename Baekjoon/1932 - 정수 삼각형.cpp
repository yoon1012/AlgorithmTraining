#include <iostream>
#include <algorithm>

using namespace std;

int a[501][501];
int d[501][501];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}

	d[1][1] = a[1][1];
	d[2][1] = d[1][1] + a[2][1];
	d[2][2] = d[1][1] + a[2][2];

	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				d[i][j] = d[i - 1][1] + a[i][j];
			}
			else if (j == i)
			{
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			}
			else
			{
				d[i][j] = max(d[i - 1][j - 1] + a[i][j], d[i - 1][j] + a[i][j]);
			}
		}
	}

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		if (max < d[n][i])
		{
			max = d[n][i];
		}
	}

	cout << max << "\n";
	return 0;
}
