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
	
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1;

		for (int j = 1; j <= i; j++)
		{
			if (a[j] < a[i])
			{
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int maxLength = 0;

	for (int i = 1; i <= n; i++)
	{
		maxLength = max(maxLength, d[i]);
	}

	cout << maxLength << "\n";
	
	return 0;
}
