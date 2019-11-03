#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
	int answer = 0;

	for (int i = 123; i <= 987; i++)
	{
		string s = to_string(i);
        
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) continue;
		else if (s[0] == '0' || s[1] == '0' || s[2] == '0') continue;

		int isCorrect = 0;

		for (int j = 0; j < baseball.size(); j++)
		{
			string target = to_string(baseball[j][0]);

			if (target[0] == target[1] || target[0] == target[2] || target[1] == target[2])
				continue;
			else if (target[0] == '0' || target[1] == '0' || target[2] == '0') continue;

			int strike = baseball[j][1], ball = baseball[j][2];

			int currentStrike = 0, currentBall = 0;

			if (s[0] == target[0]) currentStrike++;
			else if (s[0] == target[1] || s[0] == target[2]) currentBall++;

			if (s[1] == target[1]) currentStrike++;
			else if (s[1] == target[0] || s[1] == target[2]) currentBall++;

			if (s[2] == target[2]) currentStrike++;
			else if (s[2] == target[0] || s[2] == target[1]) currentBall++;

			if (strike == currentStrike && ball == currentBall)
			{
				isCorrect++;
			}
		}

		if (isCorrect == baseball.size()) answer++;
	}

	return answer;
}
