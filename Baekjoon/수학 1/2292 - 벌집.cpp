#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int i = 1;
	int current = 1;
	int step = 1;

	while (current < n)
	{
		current += step * 6;
		step++;
	}

	cout << step << endl;
	return 0;
}
