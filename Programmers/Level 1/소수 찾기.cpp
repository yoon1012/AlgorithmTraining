#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    
    bool *array = new bool[n];
    array[0] = false;

    for (int i = 1 ; i < n ; i++)
    {
        array[i] = true;
    }
    
    for (int i = 1 ; i < n ; i++)
    {
        if (array[i] == false) continue;
        
        for (int j = ((i + 1) * 2) - 1 ; j < n ; j += (i + 1))
        {
            array[j] = false;
        }
    }
    
    for (int i = 0 ; i < n ; i++)
    {
        if (array[i]) answer++;
    }
    

    delete array;
    return answer;
}
