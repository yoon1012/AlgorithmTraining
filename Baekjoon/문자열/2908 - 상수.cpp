#include <iostream>
#include <string>

using namespace std;

int reverse(const string& s)
{
	string sReversed = "";

	for (int i = s.length() - 1; i >= 0; i--)
	{
		sReversed += s[i];
	}

	return stoi(sReversed);
}

int main(void)
{
	string a, b;
	cin >> a >> b;

	int aReversed = reverse(a);
	int bReversed = reverse(b);

	if (aReversed > bReversed) cout << aReversed << endl;
	else cout << bReversed << endl;

	return 0;
}
