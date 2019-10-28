#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	short* counts = new short[10001];

	for (int i = 0; i < 10001; i++) counts[i] = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		counts[num]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		short count = counts[i];
		for (int j = 1; j <= count; j++) cout << i << "\n";
	}

	delete counts;
	return 0;
}
