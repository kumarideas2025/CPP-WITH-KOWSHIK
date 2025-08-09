#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> vec = {1, 23, 4, 5};
    // vector<int>vec(3,10);// useful for dynamic programming-->tabulation DP[]
    

        vector<int> vec1 = {1, 23, 4, 5};
        vector<int> vec2(vec1);

    for (int val : vec2)
    {
        cout << val << " ";
    }
    return 0;
}