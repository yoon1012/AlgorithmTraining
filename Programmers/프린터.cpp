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
    int copyCount = 0;

    queue<int> indices;

    for (int i = 0; i < priorities.size(); i++)
    {
        indices.push(i);
    }

    while (!isPrinted)
    {
        int front = indices.front();
        vector<int> prioritiesCopy(priorities);

        // 내림차순으로 정렬
        sort(prioritiesCopy.begin(), prioritiesCopy.end(), greater<int>());
        
        if (priorities[front] < prioritiesCopy[0] && prioritiesCopy[0] > 0)
        {
            indices.pop();
            indices.push(front);
            continue;
        }

        indices.pop();
        copyCount++;
        priorities[front] = -1; // 이미 인쇄한 문서 플래그
        
        if (front == location)
        {
            isPrinted = true;
        }
    }

    answer = copyCount;
    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
    return 0;
}
