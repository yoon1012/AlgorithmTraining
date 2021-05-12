// 힙
// 05-12-2021

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());

    while (!q.empty() && q.top() < K)
    {
        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();

        int c = a + b * 2;
        q.push(c);
        answer++;

        int top = q.top();
        q.pop();

        if (q.empty() && top < K)
        {
            return -1;
        }
        
        q.push(top);
    }

    return answer;
}

#include <iostream>

int main()
{
    int K = 7;
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };

    auto answer = solution(scoville, K);
    cout << answer << endl;
    return 0;
}
