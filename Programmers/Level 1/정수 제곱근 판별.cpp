#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long answer = n;
    long long root = static_cast<long long>(sqrt(answer));
    
    if ((root * root) == answer)
    {
        answer = (root + 1) * (root + 1);
    }
    else
    {
        answer = -1;
    }
    
    return answer;
}
