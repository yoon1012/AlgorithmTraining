#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int maxSum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				d[i] = max(d[j] + a[i], d[i]);
			}
		}

		maxSum = max(d[i], maxSum);
	}

	cout << maxSum << "\n";
	return 0;
}
