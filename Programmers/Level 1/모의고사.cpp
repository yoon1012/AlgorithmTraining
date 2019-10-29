#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Supoja
{
	int id;
	int answer;

	Supoja()
	{
		id = -1;
		answer = 0;
	}

	Supoja(int id)
	{
		this->id = id;
		answer = 0;
	}
};

int getSupojaAnswer1(int index)
{
	int answer = (index + 1) % 5;
	if (answer == 0) answer = 5;

	return answer;
}

int getSupojaAnswer2(int index)
{
	int answer = -1;
	int pattern = (index % 8);

	switch (pattern)
	{
	case 1:
		answer = 1;
		break;

	case 3:
		answer = 3;
		break;

	case 5:
		answer = 4;
		break;

	case 7:
		answer = 5;
		break;

	default:
		answer = 2;
	}

	return answer;
}

int getSupojaAnswer3(int index)
{
	int answer = -1;
	int pattern = (index % 10);

	switch (pattern)
	{
	case 0: case 1:
		answer = 3;
		break;

	case 2: case 3:
		answer = 1;
		break;

	case 4: case 5:
		answer = 2;
		break;

	case 6: case 7:
		answer = 4;
		break;

	case 8: case 9:
		answer = 5;
		break;

	default:
		answer = -1;
	}

	return answer;
}

bool compareAnswer(Supoja a, Supoja b)
{
	return a.answer < b.answer;
}

vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	vector<Supoja> supojas;

	Supoja s1(1);
	Supoja s2(2);
	Supoja s3(3);

	supojas.push_back(s1);
	supojas.push_back(s2);
	supojas.push_back(s3);

	for (int i = 0; i < answers.size(); i++)
	{
		int supojaAnswer1 = getSupojaAnswer1(i);
		int supojaAnswer2 = getSupojaAnswer2(i);
		int supojaAnswer3 = getSupojaAnswer3(i);

		if (answers[i] == supojaAnswer1) supojas[0].answer++;
		if (answers[i] == supojaAnswer2) supojas[1].answer++;
		if (answers[i] == supojaAnswer3) supojas[2].answer++;
	}

	sort(supojas.begin(), supojas.end(), compareAnswer);

	if ((supojas[0].answer == supojas[1].answer) && (supojas[1].answer == supojas[2].answer))
	{
		answer.push_back(supojas[0].id);
		answer.push_back(supojas[1].id);
		answer.push_back(supojas[2].id);
	}
	else if ((supojas[1].answer == supojas[2].answer))
	{
		answer.push_back(supojas[1].id);
		answer.push_back(supojas[2].id);
	}
	else
	{
		answer.push_back(supojas[2].id);
	}

	sort(answer.begin(), answer.end());

	return answer;
}
