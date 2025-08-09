#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(3);
    queue<int> q2;
    q2.swap(q);
    cout << "size is :" << q.size() << endl;   // 0
    cout << "size2 is :" << q2.size() << endl; // 2

    while (!q2.empty())
    {
        cout << "top value is :" << q2.front() << endl;// at first front value is 1 and that will pop out . and now front  value is 3 then 3 will pop out. 
        q2.pop();
    }
    cout << endl;
    return 0;
}
// output will come AT A  reverse fasion.