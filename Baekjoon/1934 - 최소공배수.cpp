#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
	{
		int temp = b;
		b = a;
		a = temp;
	}

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
	return (a * b) / gcd(a, b);
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}

	return 0;
}
