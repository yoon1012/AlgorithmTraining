#include <iostream>

using namespace std;

int d[201][201];

int main(void)
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
			}

			d[i][j] %= 1000000000;
		}
	}

	cout << d[K][N] << "\n";

	return 0;
}
