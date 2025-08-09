#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    // unorder map gives random values.
    unordered_map<string, int> m;
    // we can not use duplicates in unorder map.this will give 1 value like map
    m["tv"] = 1009;
    m["phone"] = 100000;
    m["headset"] = 1008;
    m["pc"] = 108;
    m["watch"] = 11008;

    for (auto val : m)
    {
        cout << val.first << " " << val.second << endl;
    }

    return 0;
}