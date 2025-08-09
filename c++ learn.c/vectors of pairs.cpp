#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> vec = {{3, 4}, {9, 6}, {12, 13}};
    vec.push_back({4, 5});// assume that we already creat  pair and it is work only to insert that.
    vec.emplace_back(4, 5);//in-place object create at the time of insertion.more faster.
    // for (pair<int, int> p : vec)
    for (auto p : vec)
    {
        cout << p.first << "  " << p.second << endl;
    }
    return 0;
}