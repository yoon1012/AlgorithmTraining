#include <iostream>

using namespace std;

long long d[91];

int main(void)
{
	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i < 91; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	int n;
	cin >> n;

	cout << d[n] << "\n";
	
	return 0;
}
