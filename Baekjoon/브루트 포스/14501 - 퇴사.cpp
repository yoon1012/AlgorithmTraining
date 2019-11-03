#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int customers[16], wages[16];
int n, totalWage;

void solve(int startDay, int wage)
{
	if (startDay == n + 1)
	{
		if (totalWage < wage) totalWage = wage;
		return;
	}
	else if (startDay > n + 1) return;

	solve(startDay + customers[startDay], wage + wages[startDay]);
	solve(startDay + 1, wage);
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> customers[i] >> wages[i];
	}

	solve(1, 0);
	cout << totalWage << endl;
	return 0;
}
