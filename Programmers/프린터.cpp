// 스택/큐
// Level 2
// 03-10-2021

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    bool isPrinted = false;

    queue<int> indices;

    for (int i = 0; i < priorities.size(); i++)
    {
        indices.push(i);
    }

    while (!isPrinted)
    {
        int front = indices.front();
        vector<int> prioritiesCopy(priorities);

        auto maxElement = *max_element(prioritiesCopy.begin(), prioritiesCopy.end());
        
        if (priorities[front] < maxElement && maxElement > 0)
        {
            indices.pop();
            indices.push(front);
            continue;
        }

        indices.pop();
        answer++;
        priorities[front] = -1;
        
        if (front == location)
        {
            isPrinted = true;
        }
    }

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
    return 0;
}
