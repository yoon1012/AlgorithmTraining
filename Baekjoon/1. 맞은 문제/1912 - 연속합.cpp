#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int d[100001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	d[1] = a[1];

	int maxSum = d[1];

	for (int i = 2; i <= n; i++)
	{
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		maxSum = max(maxSum, d[i]);
	}
	
	cout << maxSum << "\n";
	return 0;
}
