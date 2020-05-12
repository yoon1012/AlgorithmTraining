#include <iostream>

using namespace std;

int d[1001][10];
int mod = 10007;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k <= 9; k++)
			{
				d[i][k] += d[i - 1][j];
				d[i][k] %= mod;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < 10; i++)
	{
		answer += d[n][i];
	}

	cout << answer % mod << "\n";
	return 0;
}
