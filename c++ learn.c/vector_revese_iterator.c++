#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
    // with this we can access our memory location direct
    vector<int>::reverse_iterator it;
    for (it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *(it) << ""<<endl;
    }
cout<<endl;
    return 0;
}