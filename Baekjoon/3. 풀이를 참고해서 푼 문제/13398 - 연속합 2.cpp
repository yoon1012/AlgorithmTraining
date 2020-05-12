#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001][2];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	d[1][0] = a[1];
	d[1][1] = a[1];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = max(d[i - 1][0] + a[i], a[i]);
		d[i][1] = max(d[i - 1][0], d[i - 1][1] + a[i]);
	}

	int maxSum = 0;

	for (int i = 1; i <= n; i++)
	{
		maxSum = max(max(d[i][0], d[i][1]), maxSum);
	}
	
	cout << maxSum << "\n";
	return 0;
}
