#include <iostream>

using namespace std;

long long d[1000001];

long long solve(long long n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];

	d[n] = solve(n - 1) + 1;

	if (n % 3 == 0)
	{
		int div3 = solve(n / 3) + 1;

		if (div3 < d[n])
		{
			d[n] = div3;
		}
	}

	if (n % 2 == 0)
	{
		int div2 = solve(n / 2) + 1;

		if (div2 < d[n])
		{
			d[n] = div2;
		}
	}

	return d[n];
}

int main(void)
{
	long long n;
	cin >> n;
	cout << solve(n) << "\n";

	return 0;
}
