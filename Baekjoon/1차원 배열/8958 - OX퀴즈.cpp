#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string result;
		cin >> result;

		int oCount = 0;
		int score = 0;

		for (int j = 0; j < result.length(); j++)
		{
			if (result[j] == 'O')
			{
				score += 1 + oCount;
				oCount++;
			}
			else if (result[j] == 'X')
			{
				oCount = 0;
			}
		}

		cout << score << endl;
	}


	return 0;
}
