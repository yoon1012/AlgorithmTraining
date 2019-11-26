#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int count = 0;
    int currentBudget = budget;
    
    sort(d.begin(), d.end());
    
    for (auto request : d)
    {
        currentBudget -= request;
        
        if (currentBudget < 0)
        {
            break;
        }
        
        count++;
    }
    
    return count;
}
