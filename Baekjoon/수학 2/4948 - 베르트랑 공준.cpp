#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool numbers[246913];

int getPrimeNumberCount(int n)
{
	if (n == 1)
	{
		return 1;
	}

	int primeNumberCount = 0;

	for (int i = n + 1; i <= 2 * n; i++)
	{
		if (numbers[i] == true)
			primeNumberCount++;
	}

	return primeNumberCount;
}

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int input;

	for (int i = 0; i < 246913; i++)
	{
		numbers[i] = true;
	}

	numbers[1] = false;

	for (int i = 2; i < 246913; i++)
	{
		if (numbers[i] == false)
			continue;

		int j = 2;

		while (i * j < 246913)
		{
			numbers[i * j] = false;
			j++;
		}
	}

	while (true)
	{
		cin >> input;
		if (input == 0) break;

		cout << getPrimeNumberCount(input) << "\n";
	}

	return 0;
}
