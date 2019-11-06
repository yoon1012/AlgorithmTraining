#include <iostream>
#include <vector>

using namespace std;

string reverse(string::iterator& it)
{
	char cursor = *it;
	++it;

	if (cursor == 'b' || cursor == 'w')
	{
		return string(1, cursor);
	}

	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
	int n;
	cin >> n;

	vector<string> lines;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		lines.push_back(line);
	}

	for (int i = 0; i < n; i++)
	{
		string line = lines[i];
		string::iterator it = line.begin();
		cout << reverse(it) << endl;
	}

	return 0;
}
