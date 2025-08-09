#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
   vec.insert(vec.begin()+2,100);
   cout<<vec.size()<<endl;

    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}