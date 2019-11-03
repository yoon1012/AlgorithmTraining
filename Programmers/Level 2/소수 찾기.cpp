#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int number);
int isValid(int target, string numbers);

int solution(string numbers)
{
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());

	int number = stoi(numbers);

	for (int i = 2; i <= number; i++)
	{
		if (isValid(i, numbers))
		{
			if (isPrime(i)) answer++;
		}
	}

	return answer;
}

bool isPrime(int number)
{
	if (number < 2) return false;

	int noRemainderCount = 0;

	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0) noRemainderCount++;
	}

	if (noRemainderCount == 2) return true;
	return false;
}

int isValid(int target, string numbers)
{
	vector<bool> visited(numbers.length(), false);
	string s = to_string(target);

	for (int i = 0; i < s.length(); i++)
	{
		bool notFound = true;

		for (int k = 0; k < numbers.length(); k++)
		{
			if (s[i] == numbers[k] && !visited[k])
			{
				visited[k] = true;
				notFound = false;
				break;
			}
		}
		
		if (notFound) return false;
	}

	return true;
}
