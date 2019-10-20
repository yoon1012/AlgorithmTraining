#include <iostream>
#include <string>

using namespace std;

int solution(int n)
{
	int answer = 0;
	string number = to_string(n);

	for (int i = 0; i < number.length(); i++)
	{
		int digit = number.at(i) - '0';
		answer += digit;
	}

	return answer;
}
