#include <iostream>
#include <string>

using namespace std;

string convert(const string& s)
{
	string result = "";

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		int dial = 0;

		switch (c)
		{
			case 'A':
			case 'B':
			case 'C':
				dial = 2;
				break;

			case 'D':
			case 'E':
			case 'F':
				dial = 3;
				break;

			case 'G':
			case 'H':
			case 'I':
				dial = 4;
				break;

			case 'J':
			case 'K':
			case 'L':
				dial = 5;
				break;

			case 'M':
			case 'N':
			case 'O':
				dial = 6;
				break;

			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				dial = 7;
				break;

			case 'T':
			case 'U':
			case 'V':
				dial = 8;
				break;

			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				dial = 9;
				break;
		}

		result += to_string(dial);
	}

	return result;
}

int main(void)
{
	string s;
	cin >> s;

	string dials = convert(s);
	int time = 0;

	for (int i = 0; i < dials.length(); i++)
	{
		int dial = dials[i] - '0';
		time = time + dial + 1;
	}

	cout << time << endl;

	return 0;
}
