// 탐욕법
// 04-16-2021

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    int maxIndex  = 0;
    char maxNumber = number[0];

    for (int i = 0; i < number.size() - k; i++)
    {
        for (int j = maxIndex + 1; j <= i + k; j++)
        {
            if (maxNumber < number[j])
            {
                maxNumber = number[j];
                maxIndex = j;

                if (number[j] == '9')
                    break;
            }
        }

        answer += maxNumber;
        maxNumber = number[++maxIndex];
    }

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution("1231234", 3) << endl;
    return 0;
}
