#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string line[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> line[i];
	}

	string s1 = "";
	s1 += line[0];
	s1 += line[1];

	string s2 = "";
	s2 += line[2];
	s2 += line[3];

	long long ab = stoll(s1);
	long long cd = stoll(s2);

	cout << ab + cd << "\n";
	return 0;
}
