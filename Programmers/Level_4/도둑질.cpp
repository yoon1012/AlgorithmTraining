// 동적계획법
// 06-14-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d1[1000001] = { 0 };
int d2[1000001] = { 0 };

int solution(vector<int> money)
{
    int answer = 0;

    d1[0] = money[0];
    d1[1] = money[0];

    for (int i = 2; i < money.size(); i++)
    {
        d1[i] = max(d1[i - 1], d1[i - 2] + money[i]);
    }

    d2[1] = money[1];

    for (int i = 2; i < money.size(); i++)
    {
        d2[i] = max(d2[i - 1], d2[i - 2] + money[i]);
    }

    answer = max(d1[money.size() - 2], d2[money.size() - 1]);

    return answer;
}

#include <iostream>

int main(void)
{
    cout << solution({ 1, 2, 3, 1 });
    return 0;
}
