#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pCount = 0, sCount = 0;
    
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s.at(i) == 'P' || s.at(i) == 'p') pCount++;
        else if (s.at(i) == 'Y' || s.at(i) == 'y') sCount++;
    }

    answer = (pCount == sCount);
    
    return answer;
}
