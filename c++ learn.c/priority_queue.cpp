#include <iostream>
#include <queue>

using namespace std;
int main()
{
    priority_queue<int> q;
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);
//  as priority queue gives us largest  value in a stack. so we get a sorted queue .
    while (!q.empty())
    {
        cout << "top value is :" << q.top() << endl;

        q.pop();
    }
    cout << endl;
    // so  output is:10 5 4 3
    return 0;
}
