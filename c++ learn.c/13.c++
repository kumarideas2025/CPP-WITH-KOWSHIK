#include<iostream>
#include<string>
using namespace std;

    class employee{
        public:
        string name;
        int age;
    };
    int main(){
        employee kow;
        kow.name="kowshik";
        kow.age=21;
        cout<<"the name of your is:"<<kow.name<<"salary is"<<kow.age<<endl;
    }
