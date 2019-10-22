#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s);

	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (i != 0 && s[i] == ' ')
		{
			count++;
		}
		
		if (i == s.length() - 1 && s[i] != ' ') count++;
	}

	cout << count << endl;
	return 0;
}
