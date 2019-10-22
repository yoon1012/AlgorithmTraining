#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int r;
		cin >> r;

		string s;
		cin >> s;

		string p = "";

		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < r; k++)
			{
				p += s[j];
			}
		}

		cout << p << endl;
	}

	return 0;
}
