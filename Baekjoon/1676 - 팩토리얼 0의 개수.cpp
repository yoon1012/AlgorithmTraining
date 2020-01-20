#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int count = 0;

	for (int i = n; i >= 5; i--)
	{
		int divisor = 5;

		// 제곱 수에 대해 생각하지 않았다.
		while (divisor <= i)
		{
			if (i % divisor == 0)
			{
				count++;
			}

			divisor *= 5;
		}
	}

	cout << count << "\n";
	return 0;
}
