#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	cout << result << "\n";
	return 0;
}
