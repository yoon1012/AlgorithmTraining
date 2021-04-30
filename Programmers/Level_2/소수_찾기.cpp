// 완전탐색
// 03-22-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool prime[10000000] = {true};

void initPrime()
{
    prime[0] = false;
    prime[1] = false;

    for (auto i = 2; i < 1000000; i++)
    {
        prime[i] = true;
    }

    for (auto i = 2; i * i < 1000000; i++)
    {
        if (prime[i])
        {
            for (auto j = i * i; j < 1000000; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    initPrime();

    vector<char> digits;
    for (auto number : numbers)
    {
        digits.push_back(number);
    }

    sort(digits.begin(), digits.end());
    vector<int> results;

    do
    {
        string result = "";
        for (auto digit : digits)
        {
            result += digit;

            auto number = stoi(result);
            if (prime[number])
            {
                results.push_back(number);
            }
        }

    } while (next_permutation(digits.begin(), digits.end()));

    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());
    
    answer = results.size();
    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution("011") << endl;
    return 0;
}
