#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool* numbers = new bool[1000001];

	for (int i = 0; i < 1000001; i++)
	{
		numbers[i] = true;
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (i == 1)
		{
			numbers[i] = false;
			continue;
		}
		else if (!numbers[i])
		{
			continue;
		}

		int multiplier = 2;
		while (multiplier * i <= 1000000)
		{
			numbers[multiplier * i] = false;
			multiplier++;
		}
	}

	for (int i = 0; i < 100000; i++)
	{
		int n;
		cin >> n;

		if (n == 0) break;

		int a = -1, b = -1;

		for (int i = 2; i <= n - i; i++)
		{
			int j = n - i;

			if (numbers[i] && numbers[j])
			{
				a = i;
				b = j;
				break;
			}
		}

		if (a == -1 || b == -1)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << n << " = " << a << " + " << b << "\n";
	}

	return 0;
}
