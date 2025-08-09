#include <iostream>
#include<vector>
using namespace std;

int main(){
vector<int>vec;

vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.push_back(4);
vec.push_back(5);
vec.emplace_back(6);
vec.pop_back();

cout<<vec.size()<<endl;
cout<<vec.capacity()<<endl;
 

for(int val :vec){
    cout<<val<<" ";
}
// cout<<"val at index 2...."<<vec[2]<<"or"<<vec.at(2)<<endl;
cout<<"val at first   "<<vec.front()<<endl;
cout<<"val at last   "<<vec .back()<<endl;
    return 0;
}