#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int last = arr[0];
        
    for (int i = 0 ; i < arr.size() ; i++)
    {
        if (i == 0)
        {
            last = arr[0];
        }
        else if (arr[i] == last)
        {
            continue;
        }
        
        last = arr[i];
        answer.push_back(arr[i]);
    }

    return answer;
}
