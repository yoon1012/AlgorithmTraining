#include <iostream>

using namespace std;

int main(void)
{
	int arr[15][15];

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			arr[i][j] = -1;
		}
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k, n;
		cin >> k >> n;

		for (int i = 0; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j == 1) arr[i][j] = 1; // 1호
				else if (i == 0) arr[i][j] = j; // 0층
			}
		}

		for (int j = 2; j <= n; j++)
		{
			for (int i = 1; i <= k; i++)
			{
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		cout << arr[k][n] << endl;
	}

	return 0;
}
