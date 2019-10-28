#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> numbers;

    for (int i = 0 ; i < n ; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end());

    for (auto number : numbers)
    {
        cout << number << "\n";
    }

    return 0;
}
