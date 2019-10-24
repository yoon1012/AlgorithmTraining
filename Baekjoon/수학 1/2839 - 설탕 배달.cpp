#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int count = 0;

	while (true)
	{
		if (n % 5 == 0)
		{
			count += (n / 5);
			break;
		}

		// 5로 나눠 떨어질 때까지 3을 이용
		n -= 3;
		count++;

		if (n < 0) break;
	}

	if (n < 0) cout << -1 << endl;
	else cout << count << endl;
	return 0;
}
