#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"ENTER NUMBER1"<<endl;
    cin>>a;

    cout<<"ENTER NUMBER2"<<endl;
    cin>>b;


    cout<<"function is"<<add(a,b);
    return 0;
}

int add(int a,int b){
    int c;
    c=a+b;
    return c;
}