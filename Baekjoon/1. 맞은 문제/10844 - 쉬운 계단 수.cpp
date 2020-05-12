#include <iostream>

using namespace std;

long long d[101][10];
long long mod = 1000000000;

void solve(int n)
{
	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			d[i][j] = 0;

			if (j - 1 >= 0)
			{
				d[i][j] += d[i - 1][j - 1];
			}

			if (j + 1 <= 9)
			{
				d[i][j] += d[i - 1][j + 1];
			}

			d[i][j] %= mod;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	solve(n);

	int answer = 0;

	for (int i = 0; i <= 9; i++)
	{
		answer += d[n][i];
	}

	answer %= mod;
	cout << answer << "\n";

	return 0;
}
