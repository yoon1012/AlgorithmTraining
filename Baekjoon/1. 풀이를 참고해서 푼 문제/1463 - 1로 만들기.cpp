#include <iostream>

using namespace std;

int d[1000001];

int answer(int n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];

	d[n] = answer(n - 1) + 1;

	if (n % 2 == 0)
	{
		int result = answer(n / 2) + 1;

		if (d[n] > result)
		{
			d[n] = result;
		}
	}

	if (n % 3 == 0)
	{
		int result = answer(n / 3) + 1;

		if (d[n] > result)
		{
			d[n] = result;
		}
	}

	return d[n];
}

int main(void)
{
	int n;
	cin >> n;

	cout << answer(n) << "\n";
	return 0;
}
