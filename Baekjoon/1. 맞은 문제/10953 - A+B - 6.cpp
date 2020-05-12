#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	
	for (int i = 0 ; i < t ; i++)
	{
		char str[4];
		cin >> str;

		cout << (str[0] - '0') + (str[2] - '0') << "\n";
	}

	return 0;
}
