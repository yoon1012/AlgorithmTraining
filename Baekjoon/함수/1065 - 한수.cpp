#include <iostream>
#include <string>

using namespace std;

bool isHansu(int n)
{
	string nString = to_string(n);
	
	if (nString.length() == 1) return true;

	int n0 = nString[0] - '0';
	int n1 = nString[1] - '0';

	int difference = n1 - n0;

	for (int i = 1; i < nString.length() - 1; i++)
	{
		int ni = nString[i] - '0';
		int ni_1 = nString[i + 1] - '0';

		if (ni_1 - ni != difference)
			return false;
	}

	return true;
}

int main(void)
{
	int n;
	cin >> n;

	int hansuCount = 0;

	for (int i = 0; i < n ; i++)
	{
		if (isHansu(i + 1))
			hansuCount++;
	}

	cout << hansuCount << endl;
	return 0;
}
