#include <iostream>

using namespace std;

bool isPrimeNumber(int n)
{
	if (n == 1) return false;
	
	int noRemainderCount = 0;

	for (int i = 1; i <= n; i++)
	{
		if ((n % i) == 0)
		{
			noRemainderCount++;
		}
	}

	if (noRemainderCount == 2)
	{
		return true;
	}

	return false;
}

int main(void)
{
	int n;
	cin >> n;

	int primeNumberCount = 0;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		if (isPrimeNumber(input))
		{
			primeNumberCount++;
		}
	}

	cout << primeNumberCount << "\n";
	return 0;
}
