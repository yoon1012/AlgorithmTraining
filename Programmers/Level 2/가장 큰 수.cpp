#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    vector<string> numbersString;
    
    for (auto number : numbers)
    {
        numbersString.push_back(to_string(number));
    }
    
    sort(numbersString.begin(), numbersString.end(), compare);
    string answer = "";
    
    for (auto numberString : numbersString)
    {
        answer += numberString;
    }
    
    // 0만 들어간 배열 주의
    if (answer[0] == '0') return "0";
    return answer;
}
