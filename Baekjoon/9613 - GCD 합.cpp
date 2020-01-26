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
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		long long* numbers = new long long[n];
		long long gcdSum = 0;

		for (int j = 0; j < n; j++)
		{
			cin >> numbers[j];
		}

		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				gcdSum += gcd(numbers[j], numbers[k]);
			}
		}

		cout << gcdSum << "\n";
		delete[] numbers;
	}

	return 0;
}
