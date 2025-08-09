#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
     //  This means you declare a variable with auto, 
    // and the compiler infers its actual type based on the value or expression used to initialize it. 
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *(it) << ""<<endl;
    }
cout<<endl;
    return 0;
}