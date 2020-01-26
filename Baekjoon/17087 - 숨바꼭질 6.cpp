#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	if (a < b)
	{
		long long temp = b;
		b = a;
		a = temp;
	}

	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(void)
{
	long long n, s;
	cin >> n >> s;

	long long* siblings = new long long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> siblings[i];
	}

	long long currentGcd = llabs(siblings[0] - s);

	for (int i = 1; i < n; i++)
	{
		long long distance = llabs(siblings[i] - s);
		currentGcd = gcd(currentGcd, distance);
	}

	cout << currentGcd << "\n";
	return 0;
}
