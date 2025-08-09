#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
    // with this we can access our memory location direct
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *(it) << ""<<endl;
    }
cout<<endl;
    return 0;
}