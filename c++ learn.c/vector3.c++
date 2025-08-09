#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
    // vec.erase(vec.begin());
    // vec.erase(vec.begin()+2);
    vec.erase(vec.begin()+1,vec.begin()+3);

    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}