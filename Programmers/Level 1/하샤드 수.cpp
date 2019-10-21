#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    bool answer = true;
    
    string xStr = to_string(x);
    int sum = 0;
    
    for (int i = 0 ; i < xStr.length() ; i++)
    {
        sum += xStr[i] - '0';
    }
    
    if (x % sum == 0) answer = true;
    else answer = false;
    
    return answer;
}
