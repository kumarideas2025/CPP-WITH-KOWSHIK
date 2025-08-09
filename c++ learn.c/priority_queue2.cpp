#include <iostream>
#include <queue>
#include<vector>
using namespace std;
int main()
{
    // this greater functor will give us a smaller to large value output .
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);
     while (!q.empty())
    {
        cout << "top value is :" << q.top() << endl;

        q.pop();
    }
    cout << endl;
    // so  output is:3  4 5 10
    return 0;
}
