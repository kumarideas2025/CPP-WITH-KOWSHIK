#include <iostream>
#include <map>
using namespace std;
int main()
{
    multimap<string, int> m;
    // we can not use [] here.
    m.emplace("tv", 126);
    m.emplace("tv", 126);
    m.emplace("tv", 126);
    m.emplace("tv", 126);
    m.emplace("tv", 126);
    
    // m.erase("tv"); // will del all tv
    m.erase(m.find("tv"));// that will del only 1 with memory location
    for (auto val : m)
    {
        cout << val.first << " " << val.second << endl;
    }

    return 0;
}