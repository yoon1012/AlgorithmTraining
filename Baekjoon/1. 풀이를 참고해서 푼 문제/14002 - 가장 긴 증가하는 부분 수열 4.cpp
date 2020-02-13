#include <iostream>

using namespace std;

int a[1001];
int d[1001];
int v[1001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	std::fill_n(d, 1001, 1);
	std::fill_n(v, 1001, 0);
	
	int max = 0;
	int maxIndex = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// 이전 값이 자신보다 작아야 한다.
			if (a[i] > a[j] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}

		if (max < d[i])
		{
			max = d[i];
			maxIndex = i;
		}		
	}

	cout << max << "\n";

	int result[1001];

	for (int i = 0; i < max; i++)
	{
		result[i] = a[maxIndex];
		maxIndex = v[maxIndex];
	}

	for (int i = 0; i < max; i++)
	{
		cout << result[max - 1 - i];
		cout << " ";
	}

	cout << "\n";
	return 0;
}
