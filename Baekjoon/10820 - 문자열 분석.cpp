#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	for (int i = 0; i < 100; i++)
	{
		string line;
		getline(cin, line);

		if (line.length() == 0)
			break;

		int count[4] = { 0, 0, 0, 0 };

		for (char c : line)
		{
			if (islower(c))
			{
				count[0]++;
			}
			else if (isupper(c))
			{
				count[1]++;
			}
			else if (isdigit(c))
			{
				count[2]++;
			}
			else if (c == ' ')
			{
				count[3]++;
			}
		}

		cout << count[0] << " " << count[1] << " "
			 << count[2] << " " << count[3] << "\n";
	}

	return 0;
}
