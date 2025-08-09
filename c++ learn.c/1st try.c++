#include<iostream>
using namespace std;

int main(){
    int age;
    cout<<"enter the age"<<endl;
    cin>>age;
    switch(age){
        case 12:
        cout<<"your are 12 year";
        break;

         case 14:
        cout<<"your are 14 year";
        break;

         case 18:
        cout<<"your are 18 year";
        break;


        default:
        cout<<"you are neither 12 nor 18 years old";
        break;
    }
    return 0;
}
