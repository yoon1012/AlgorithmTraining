#include <iostream>

using namespace std;

int f(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;

	return f(n - 1) + f(n - 2);
}

int main(void)
{
	int n;
	cin >> n;

	cout << f(n) << endl;
	return 0;
}
