#include <iostream>

using namespace std;

bool primeNumbers[1000001];

int main(void)
{
	for (int i = 0; i < 1000001; i++)
	{
		if (i == 0 || i == 1)
		{
			primeNumbers[i] = false;
			continue;
		}

		primeNumbers[i] = true;
	}

	for (int i = 2; i < 1000001; i++)
	{
		int multiplier = 2;

		while (i * multiplier < 1000001)
		{
			primeNumbers[i * multiplier] = false;
			multiplier++;
		}
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int count = 0;

		for (int j = 2; j < 1000001; j++)
		{
			int b = n - j;

			if (primeNumbers[j] && primeNumbers[b])
			{
				count++;
			}

			if (j >= b) break;
		}

		cout << count << "\n";
	}

	return 0;
}
