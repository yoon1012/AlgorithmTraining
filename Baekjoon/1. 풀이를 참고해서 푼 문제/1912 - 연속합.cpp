#include <iostream>

using namespace std;

int a[100001];
int d[100001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	std::fill_n(d, 100001, 0);
	
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			d[i] = a[i];
		}
		else if (d[i - 1] + a[i] > a[i])
		{
			d[i] = d[i - 1] + a[i];
		}
		else
		{
			d[i] = a[i];
		}
	}

	int max = d[1];

	for (int i = 2; i <= n; i++)
	{
		if (max < d[i])
		{
			max = d[i];
		}
	}

	cout << max << "\n";
	return 0;
}
