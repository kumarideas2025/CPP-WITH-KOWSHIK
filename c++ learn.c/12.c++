#include<iostream>
#include<string>
using namespace std;
int main(){
    int a=99;
    int *ptra;
     ptra=&a;

    cout<<"value is :"<<ptra;
    cout<<"value is  : "<<*ptra;
}