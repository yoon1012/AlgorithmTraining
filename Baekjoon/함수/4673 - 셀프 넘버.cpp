#include <iostream>
#include <string>

using namespace std;

int d(int n)
{
	string nString = to_string(n);
	int sum = n;

	for (int i = 0; i < nString.length(); i++)
	{
		sum += nString[i] - '0';
	}

	return sum;
}

int main(void)
{
	bool arr[10000] = { false };

	for (int i = 0; i < 10000; i++)
	{
		int n = d(i + 1);

		if (n <= 10000)
		{
			arr[n - 1] = true;
		}
	}

	for (int i = 0; i < 10000; i++)
	{
		if (!arr[i]) cout << i + 1 << endl;
	}

	return 0;
}
