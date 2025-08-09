#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(4);
    l.push_back(3);
    l.push_front(2);
    l.push_front(1);
    l.emplace_back(5);

    l.pop_back();
    l.pop_front();

    for(int val:l){
        cout<<val<<" "<<endl;
    }
    return 0;
}