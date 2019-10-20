#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	int cycle = 0;
	cin >> n;

	int input = n;

	while (true)
	{
		int a, b, sum;

		a = input / 10;
		b = input % 10;

		sum = a + b;

		if (sum >= 10)
		{
			sum %= 10;
		}

		input = b * 10 + sum;
		cycle++;

		if (input == n) break;
	}

	cout << cycle << endl;

	return 0;
}
