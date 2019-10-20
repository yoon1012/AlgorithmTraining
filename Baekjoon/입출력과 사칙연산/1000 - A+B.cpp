#include <iostream>

using namespace std;

int main(void)
{
	int a = 0, b = 0;

	while ((a <= 0 || a >= 10) || (b <= 0 || b >= 10))
	{
		cin >> a >> b;
	}

	cout << a + b << endl;

	return 0;
}
