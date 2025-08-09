#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l = {4, 6, 8, 2, 45, 7, 8};

    for (int val : l)
    {
        cout << val << " " << endl;
    }
        // random access is not  possible.l[2] will give error.

    return 0;
}