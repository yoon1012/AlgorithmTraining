#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	
	return a.size() < b.size();
}

int main(void)
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		if (i > 0)
		{
			if (v[i - 1] == v[i]) continue;
		}

		cout << v[i] << "\n";
	}

	return 0;
}
