#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1; // 아무것도 고르지 않는 경우도 일단 계산
    unordered_map<string, int> um;

    for (auto item : clothes)
    {
        um[item[1]] += 1;
    }

    for (auto it = um.begin(); it != um.end() ; it++)
    {
        answer *= it->second + 1;
    }

    return answer - 1; // 아무것도 고르지 않은 경우를 빼기
}

#include <iostream>

int main(void)
{
    cout << solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});

    return 0;
}
