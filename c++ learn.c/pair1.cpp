#include <iostream>
#include <list>
using namespace std;

int main()
{
    pair<int, pair<char, int>> p = {1, {'k', 3}};

    cout << p.first << endl; // 1
    cout << p.second.first << endl;  //k
    cout << p.second.second << endl; //3

    return 0;
}