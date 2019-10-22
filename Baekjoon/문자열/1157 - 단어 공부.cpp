#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
	int occur = 0;
	char letter = 0;
};

bool compare(Pair p1, Pair p2)
{
	return p1.occur < p2.occur;
}

int main(void)
{
	vector<Pair> pairs;

	for (int i = 0; i < 26; i++)
	{
		Pair pair;
		pair.occur  = 0;
		pair.letter = i + 'A';

		pairs.push_back(pair);
	}

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		char c = toupper(s[i]);
		int index = c - 'A';

		pairs[index].occur += 1;
	}

	sort(pairs.begin(), pairs.end(), compare);
	
	int maxCount = 1;
	int maxOccur = pairs[25].occur;
	char result  = pairs[25].letter;

	for (int i = 24; i >= 0; i--)
	{
		if (pairs[i].occur == maxOccur)
		{
			result = '?';
			break;
		}
	}

	cout << result << endl;

	return 0;
}
