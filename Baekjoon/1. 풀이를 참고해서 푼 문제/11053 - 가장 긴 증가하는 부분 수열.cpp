#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	std::fill_n(d, 1001, 1);
	
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// 이전 값이 자신보다 작아야 한다.
			if (a[i] > a[j])
			{
				d[i] = max(d[i], d[j] + 1);
			}
		}

		result = max(result, d[i]);
	}

	cout << result << endl;
	return 0;
}
