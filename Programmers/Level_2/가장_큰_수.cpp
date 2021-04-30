// 정렬
// 03-10-2021

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(string &a, string &b)
{
    return a + b > b + a;
}

#include <iostream>

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> numberStrings;
    for (auto number : numbers)
    {
        numberStrings.push_back(to_string(number));
    }

    sort(numberStrings.begin(), numberStrings.end(), compare);

    for (auto numberString : numberStrings)
    {
        answer += numberString;
    }

    if (answer[0] == '0') answer = "0"; // 0만 들어있는 경우
    return answer;
}

#include <iostream>

int main(void)
{
    auto answer = solution({ 6, 10, 2 });
    cout << answer << endl;    
    return 0;
}
