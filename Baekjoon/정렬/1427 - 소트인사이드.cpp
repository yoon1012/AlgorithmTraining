#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
	return a > b;
}

int main(void)
{
	int n;
	cin >> n;

	string s = to_string(n);
	vector<char> v;

	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s.at(i));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}

	cout << endl;
	return 0;
}
