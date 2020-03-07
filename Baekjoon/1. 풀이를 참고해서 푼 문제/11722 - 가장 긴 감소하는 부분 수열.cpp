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
	
	int maxLength = 0;
	std::fill_n(d, 1001, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i] < a[j])
			{
				d[i] = max(d[i], d[j] + 1);
			}
		}

		maxLength = max(d[i], maxLength);
	}

	cout << maxLength << "\n";
	return 0;
}
