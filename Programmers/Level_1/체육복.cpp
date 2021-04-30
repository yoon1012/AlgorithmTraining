// 탐욕법
// 03-22-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> students(n);

    for (auto i = 0; i < n; i++)
    {
        auto student = i + 1;
        students[i] = 0;

        auto lostIt = find(lost.begin(), lost.end(), student);

        if (lostIt != lost.end())
        {
            students[i]--;
        }

        auto reserveIt = find(reserve.begin(), reserve.end(), student);
        if (reserveIt != reserve.end())
        {
            students[i]++;
        }
    }

    for (auto i = 0; i < n; i++)
    {
        if (students[i] < 1)
            continue;

        if (i == 0 && students[i + 1] < 0)
        {
            students[i]--;
            students[i + 1]++;
        }
        else if (i == n - 1 && students[i - 1] < 0)
        {
            students[i]--;
            students[i - 1]++;
        }
        else if (students[i - 1] < 0)
        {
            students[i]--;
            students[i - 1]++;
        }
        else if (students[i + 1] < 0)
        {
            students[i]--;
            students[i + 1]++;
        }
    }

    for (auto student : students)
    {
        if (student > -1)
        {
            answer++;
        }
    }

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution(5, {2, 4}, {1, 3, 5}) << endl;
    return 0;
}
