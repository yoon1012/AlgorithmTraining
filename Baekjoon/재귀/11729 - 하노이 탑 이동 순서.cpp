#include <iostream>
#include <cmath>

using namespace std;

void solve(int n, int from, int temp, int to)
{
	if (n == 0) return;

	solve(n - 1, from, to, temp);
	cout << from << " " << to << "\n";
	solve(n - 1, temp, from, to);
}

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int count = 1;

	for (int i = 1; i <= n; i++)
	{
		count *= 2;
	}

	cout << count - 1 << "\n";
	solve(n, 1, 2, 3);

	return 0;
}
