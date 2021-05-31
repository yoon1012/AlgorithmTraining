// 동적계획법
// 05-31-2021

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int d[500][500];

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    
    d[0][0] = triangle[0][0];
    
    for (int i = 1 ; i < triangle.size() ; i++)
    {
        for (int j = 0; j <= i ; j++)
        {
            if (j == 0)
            {
                d[i][j] = d[i-1][j] + triangle[i][j];
            }
            else if (j == i)
            {
                d[i][j] = d[i-1][j-1] + triangle[i][j];
            }
            else
            {
                d[i][j] = max(d[i-1][j], d[i-1][j-1]) + triangle[i][j];
            }
        }
    }
    
    for (int i = 0 ; i < triangle.size() ; i++)
    {
        if (answer < d[triangle.size()-1][i])
        {
            answer = d[triangle.size()-1][i];
        }
    }
    
    return answer;
}

int main(void)
{
    int answer =
        solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
    cout << answer << endl;
    return 0;
}
