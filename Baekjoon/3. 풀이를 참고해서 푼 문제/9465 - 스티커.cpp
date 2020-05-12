#include <iostream>
#include <algorithm>

using namespace std;

int a[2][100000];
int d[2][100000];

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}

		d[0][0] = a[0][0];
		d[1][0] = a[1][0];

		d[0][1] = a[0][1] + d[1][0];
		d[1][1] = a[1][1] + d[0][0];

		for (int i = 2; i < n; i++)
		{
			d[0][i] = a[0][i] + max(d[1][i - 1], d[1][i - 2]);
			d[1][i] = a[1][i] + max(d[0][i - 1], d[0][i - 2]);
		}

		cout << max(d[0][n - 1], d[1][n - 1]) << "\n";
	}

	return 0;
}
