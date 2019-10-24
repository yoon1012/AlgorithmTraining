#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long x, y;
		cin >> x >> y;

		long long j = 1;
		long long distance = y - x;

		while (j * j <= distance)
		{
			j++;
		}

		j--;

		long long remainder = distance - (j * j);
		long long count = (long long)ceil((double)remainder / j);

		cout << j * 2 - 1 + count << endl;
	}
	
	return 0;
}
