#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d1[1001], d2[1001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		d1[i] = 1;

		for (int j = 1; j <= i; j++)
		{
			if (a[j] < a[i])
			{
				d1[i] = max(d1[i], d1[j] + 1);
			}
		}
	}

	for (int i = n; i >= 1; i--)
	{
		d2[i] = 1;

		for (int j = n; j >= i; j--)
		{
			if (a[j] < a[i])
			{
				d2[i] = max(d2[i], d2[j] + 1);
			}
		}
	}

	int maxLength = 0;

	for (int i = 1; i <= n; i++)
	{
		maxLength = max(maxLength, d1[i] + d2[i] - 1);
	}

	cout << maxLength << "\n";
	return 0;
}
