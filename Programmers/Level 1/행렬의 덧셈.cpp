#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    
    for (int i = 0 ; i < arr1.size() ; i++)
    {
        vector<int> data1 = arr1[i];
        vector<int> data2 = arr2[i];
        vector<int> result;
        
        for (int j = 0 ; j < data1.size() ; j++)
        {
            result.push_back(data1[j] + data2[j]);
        }
        
        answer.push_back(result);
    }
    
    return answer;
}
