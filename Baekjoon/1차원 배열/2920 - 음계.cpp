#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int arr[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}

	string answer = "";

	for (int i = 0; i < 8; i++)
	{
		if (arr[0] == 8) answer = "descending";
		else if (arr[0] == 1) answer = "ascending";
		else if (arr[0] > 1 && arr[0] < 8)
		{
			answer = "mixed";
			break;
		}

		if (answer == "ascending" && (i + 1) != arr[i])
		{
			answer = "mixed";
			break;
		}
		else if (answer == "descending" && (8 - i) != arr[i])
		{
			answer = "mixed";
			break;
		}
	}

	cout << answer;
}
