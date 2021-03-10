// 스택/큐
// 03-10-2021

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> order;

    for (int i = 0; i < progresses.size(); i++)
    {
        order.push(i);
    }

    while (!order.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];

            if (progresses[i] > 100) progresses[i] = 100;
        }

        int releaseCount = 0;

        while (!order.empty() && progresses[order.front()] == 100)
        {
            releaseCount++;
            order.pop();
        }

        if (releaseCount > 0)
        {
            answer.push_back(releaseCount);
        }
    }

    return answer;
}

#include <iostream>

int main(void)
{
    auto answer = solution({ 93, 30, 55 }, { 1, 30, 5 });

    for (auto a : answer)
    {
        cout << a << " ";
    }

    cout << endl;
    return 0;
}
