#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;

    // 입력 개수가 주어지지 않았다.
	while (cin >> a >> b)
	{
		cout << a + b << "\n";
	}

	return 0;
}
