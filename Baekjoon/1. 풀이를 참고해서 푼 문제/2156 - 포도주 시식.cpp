#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];
int d[10001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	d[0] = 0;
	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++)
	{
		d[i] = max(d[i - 1], max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]));
	}

	cout << d[n] << "\n";
	return 0;
}
