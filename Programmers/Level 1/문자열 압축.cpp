#include <string>
#include <vector>

using namespace std;

int trim(string& s, int unitSize)
{
	vector<string> v;
	int unitCount;
	
	string result = "";

	if (s.length() % unitSize == 0)
	{
		unitCount = s.length() / unitSize;
	}
	else
	{
		unitCount = (s.length() / unitSize) + 1;
	}

	for (int i = 0; i < unitCount; i++)
	{
		v.push_back(s.substr(i * unitSize, unitSize));
	}

	for (int i = 0; i < unitCount; i++)
	{
		int j = -1;

		for (j = i + 1; j < unitCount; j++)
		{
			if (v[i] != v[j])
			{
				break;
			}
		}

		if (j == i + 1)
		{
			result += v[i];
		}
		else
		{
			result += to_string(j - i) + v[i];
			i = j - 1;
		}
	}

	return result.length();
}

int solution(string s)
{
	int answer = s.length();
	int maxLength = s.length() / 2;

	for (int i = 1; i <= maxLength; i++)
	{
		int result = trim(s, i);
		
		if (result < answer)
		{
			answer = result;
		}
	}

	return answer;
}
