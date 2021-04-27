// 탐욕법
// 04-26-2021

// 벡터에서 제거 → 시간 초과

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;

    while (start <= end)
    {
        if (people[start] + people[end] <= limit)
        {
            start++;
        }
        
        end--;
        answer++;
    }

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution({70, 80, 50, 10, 30, 50, 50, 40}, 100) << endl;
    return 0;
}
