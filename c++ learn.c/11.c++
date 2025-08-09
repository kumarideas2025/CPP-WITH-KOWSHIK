#include<iostream>
#include<string>
using namespace std;
int main(){
    string name="kowshik";
    cout<<"name is "<<name<<endl;
    // (0,3)---0 is index number here and starting point and 3 is for how many elements will take after 0 index= 3 element is taken
    cout<<"name is "<<name.substr(0,3)<<endl; 
        cout<<"name is "<<name.substr(2,3)<<endl;
    cout<<"name is:"<<name.length()<<endl;

}