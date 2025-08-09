#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(6);
    s.insert(4);
    s.insert(12);
    s.insert(9); // duplicate value didnot show
    cout << s.size() << endl;
    cout << "lower_bound is :" << (*s.lower_bound(4)) << endl;// if 4 already exits then output:4.
    // if it does not then bigger value than 4 is output:6.if there no bigger value output:0

    cout << "upper_bound is :" << (*s.upper_bound(4)) << endl;

    for (auto val : s)
    {
        cout << val << " " << endl;
    }

    return 0;
}

//The lower_bound function returns an iterator to the first element that is not less than the specified value, and you use * to get the actual value from that iterator.