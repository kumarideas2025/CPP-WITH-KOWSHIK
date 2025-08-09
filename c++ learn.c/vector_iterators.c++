#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 23, 4, 5};
    
    cout<<"vec.begin: "<<*(vec.begin())<<endl;
    cout<<"vec.end: "<<*(vec.end())<<endl;


    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}



// In C++, an iterator is an object that allows you to traverse the elements of a container 
// (like a set, vector, or list) without exposing the underlying structure of the container. 
// You can think of an iterator as a pointer that points to an element in the container.