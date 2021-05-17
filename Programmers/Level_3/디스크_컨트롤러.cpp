// 힙
// 05-17-2021

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int compare1(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

// 우선순위 큐 비교함수 정의
struct compare2
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int length = jobs.size();

    priority_queue<vector<int>, vector<vector<int>>, compare2> q;
    sort(jobs.begin(), jobs.end(), compare1);

    int currentTime = jobs[0][0];

    // 벡터에 남은 작업이 있거나 큐가 비지 않았을 때
    while (!jobs.empty() || !q.empty())
    {
        if (!jobs.empty() && jobs[0][0] <= currentTime)
        {
            q.push(jobs[0]);
            jobs.erase(jobs.begin());
            continue; // 같은 시간 작업 체크해야 한다.
        }

        if (!q.empty())
        {
            auto job = q.top();
            currentTime += job[1];
            answer += currentTime - job[0];
            q.pop();
        }
        else
        {
            currentTime = jobs[0][0];
        }
    }

    answer /= length;
    return answer;
}

#include <iostream>

int main()
{
    vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };

    auto answer = solution(jobs);
    cout << answer << endl;
    return 0;
}
