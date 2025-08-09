#include <iostream>
#include <stack>

using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    stack<int> s2;
    s2.swap(s);
    cout << "size is :" << s.size() << endl;   // 0
    cout << "size2 is :" << s2.size() << endl; // 2

    while (!s2.empty())
    {
        cout << "top value is :" << s2.top() << endl;// at first top value is 3 and that will pop out . and now top value is 1 then 1 will pop out. 
        s2.pop();
    }
    cout << endl;
    return 0;
}
// output will come AT A  reverse fasion.