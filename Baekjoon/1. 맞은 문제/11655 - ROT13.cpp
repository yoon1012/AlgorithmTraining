#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	string line;
	getline(cin, line);

	string answer = "";

	for (char c : line)
	{
		if (isupper(c))
		{
			int index = c - 'A';
			index += 13;

			if (index > 25) index -= 26;
			answer += 'A' + index;
		}
		else if (islower(c))
		{
			int index = c - 'a';
			index += 13;

			if (index > 25) index -= 26;
			answer += 'a' + index;
		}
		else
		{
			answer += c;
		}
	}

	cout << answer << "\n";
	return 0;
}
