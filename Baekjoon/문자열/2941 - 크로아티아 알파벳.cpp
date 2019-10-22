#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	string s;
	cin >> s;

	int i = 0;
	int count = 0;

	while (i < s.length())
	{
		switch (s[i])
		{
		case 'c':
			if (i < s.length() - 1 && (s[i + 1] == '=' || s[i + 1] == '-')) i = i + 2;
			else i++;
			break;

		case 'd':
			if (i < s.length() - 1 && (s[i + 1] == '-')) i = i + 2;
			else if (i < s.length() - 2 && s[i + 1] == 'z' && s[i + 2] == '=') i = i + 3;
			else i++;
			break;

		case 'l':
			if (i < s.length() - 1 && (s[i + 1] == 'j')) i = i + 2;
			else i++;
			break;

		case 'n':
			if (i < s.length() - 1 && (s[i + 1] == 'j')) i = i + 2;
			else i++;
			break;

		case 's':
			if (i < s.length() - 1 && (s[i + 1] == '=')) i = i + 2;
			else i++;
			break;

		case 'z':
			if (i < s.length() - 1 && (s[i + 1] == '=')) i = i + 2;
			else i++;
			break;

		default:
			i++;
			break;
		}

		count++;
	}

	cout << count << endl;

	return 0;
}
