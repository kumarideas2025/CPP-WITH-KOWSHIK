#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
   vec. clear();
   
   cout<<vec.size()<<endl;
   cout<<"is empty..."<<vec.empty()<<endl;

    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}