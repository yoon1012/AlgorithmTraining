#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    for (char a : s)
    {
        if (a < '0' || a > '9') answer = false; 
    }
    
    if (s.length() != 4 && s.length() != 6) answer = false;
    
    return answer;
}
