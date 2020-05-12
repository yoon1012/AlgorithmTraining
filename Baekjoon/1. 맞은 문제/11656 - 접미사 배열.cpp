#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string input;
	cin >> input;

	vector<string> suffixes;

	for (int i = 0; i < input.size(); i++)
	{
		string suffix(input.begin() + i, input.end());
		suffixes.push_back(suffix);
	}

	sort(suffixes.begin(), suffixes.end());

	for (string s : suffixes)
	{
		cout << s << "\n";
	}
	
	return 0;
}
