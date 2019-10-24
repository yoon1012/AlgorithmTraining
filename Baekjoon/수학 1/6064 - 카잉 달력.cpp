#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int year = -1;
		int end = lcm(m, n);

		for (int i = 0; x + m * i <= end; i++)
		{
			if ((x + m * i) % n == y % n)
			{
				year = x + m * i;
				break;
			}
		}

		cout << year << endl;
	}

	return 0;
}
