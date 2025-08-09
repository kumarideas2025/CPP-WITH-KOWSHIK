#include <iostream>
#include <list>
using namespace std;

int main()
{
    pair<string, int> p = {"kowshik", 6};
    // pair<int , int> p = {20, 6};
    // pair<char , int> p = {'a', 6};

    cout << p.first << endl;
    cout << p.second << endl;

    return 0;
}