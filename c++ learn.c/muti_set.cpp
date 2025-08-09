#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(6);
    s.insert(4);
    s.insert(3);
    s.insert(4); 

    for (auto val : s)
    {
        cout << val << " " << endl;
    }

    return 0;
}