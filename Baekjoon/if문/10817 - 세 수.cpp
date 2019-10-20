#include <iostream>

using namespace std;

int main(void)
{
    int num[3];
    
    cin >> num[0] >> num[1] >> num[2];

    for (int i = 0 ; i < 3 - 1 ; i++)
    {
        for (int j = 0 ; j < 3 - 1 - i ; j++)
        {
            if (num[j] < num[j + 1])
            {
                int temp;
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    cout << num[1] << endl;
    return 0;
}
