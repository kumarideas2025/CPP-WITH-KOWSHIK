#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, int> m;
    m["tv"] = 1009;
    m["phone"] = 100000;
    m["headset"] = 1008;
    m["pc"] = 108;
    m["watch"] = 11008;
    // output will come with ascending order of (A-Z). h comes first then p , p comes first then t,w
    // so output will show--->headphone,pc,phone,tv,watch

    m.insert({"camera", 1022});
    m.emplace("pen", 100069);
    m.erase("pc");

    for (auto val : m)
    {
        cout << val.first << " " << val.second << endl;
    }
    cout << "count= " << m.count("tv") << endl;
    cout << "count= " << m["tv"] << endl;

    // m.end() means we not found the value inside
    if (m.find("camera") != m.end())
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}