#include <iostream>

using namespace std;

int summation(int n)
{
	if (n <= 0) return 0;
	return n + summation(n - 1);
}

int main(void)
{
	int n;
	cin >> n;

	int i = 1;

	while (true)
	{
		if (n == 1)
		{
			i = 0;
			break;
		}
		else if (summation(i) >= n)
		{
			i -= 1;
			break;
		}

		i++;
	}

	int sum = summation(i);
	int remainder = n - sum;
	int numerator, denominator;

	if (i % 2 == 0)
	{
		numerator = i + 2 - remainder;
		denominator = remainder;
	}
	else
	{
		numerator = remainder;
		denominator = i + 2 - remainder;
	}

	cout << numerator << "/" << denominator << endl;
	return 0;
}
