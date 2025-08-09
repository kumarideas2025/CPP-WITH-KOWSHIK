#include <iostream>
#include <deque>
using namespace std;

int main()
{
    
    deque<int> d = {4, 6, 8, 2, 45, 7, 8};

    for (int val : d)
    {
        cout << val << " " << endl;
    }
    // random access possible.d[2]
    cout<<"value is :"<<d[2]<<" "<<endl;
    return 0;
}