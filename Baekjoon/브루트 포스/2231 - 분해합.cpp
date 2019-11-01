#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDecomposedSum(int number)
{
	int sum = number;

	while (number != 0)
	{
		sum += number % 10;
		number = number / 10;
	}

	return sum;
}

int solve(int number)
{
	int i = 1;

	for (int i = 1; i <= number; i++)
	{
		int decomposedSum = getDecomposedSum(i);

		if (decomposedSum == number)
		{
			return i;
		}
	}

	return 0;
}

int main(void)
{
	int n;
	cin >> n;

	cout << solve(n) << endl;
}
