// DFS/BFS
// 06-15-2021

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int target, int sum, int count)
{
    if (count == numbers.size())
    {
        if (target == sum) answer++;
        return;
    }
    
    dfs(numbers, target, sum + numbers[count], count + 1);
    dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target)
{
    dfs(numbers, target, 0, 0);
    return answer;
}

int main(void)
{
    int answer = solution({1, 1, 1, 1, 1}, 3);
    cout << answer << endl;
    return 0;
}
