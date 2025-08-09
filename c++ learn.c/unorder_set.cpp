#include <iostream>
#include <set>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(6);
    s.insert(4);
    s.insert(3);
    s.insert(4); 
// randomly and not duplicate values.
    for (auto val : s)
    {
        cout << val << " " << endl;
    }

    return 0;
}
// lower_bound and upper_bound can not be done in a unsorted data.