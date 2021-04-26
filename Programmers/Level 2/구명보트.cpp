// 탐욕법
// 04-26-2021
// 시간 초과

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    // 몸무게와 제한이 같은 경우
    if (people[0] == limit)
    {
        answer = people.size();
        return answer;
    }

    const int initialSize = people.size();
    
    while (!people.empty())
    {
        if (answer >= initialSize)
            break;

        int max = people[people.size() - 1];
        int restLimit = limit - max;

        if (restLimit >= people[0] && people.size() > 1)
        {
            auto result = lower_bound(people.begin(), people.end() - 1, restLimit);

            if (result != people.end())
            {
                if (*result > restLimit || distance(result, people.end() - 1) == 0)
                {
                    result--;
                }

                result = find(people.begin(), people.end() - 1, *result);

                if (result != people.end())
                {
                    answer++;
                    people.pop_back();
                    people.erase(result);
                    continue;
                }
            }
        }

        answer++;
        people.pop_back();
    }

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution({70, 80, 50, 10, 30, 50, 50, 40}, 100) << endl;
    return 0;
}
