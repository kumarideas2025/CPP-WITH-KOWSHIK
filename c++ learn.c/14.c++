#include<iostream>
#include<string>
using namespace std;

    class employee{
        public:
        string name;
        int age;
        void printdel(){
                    cout<<"the name of your is:"<<this->name<<"salary is"<<this->age<<endl;
        }
    };
    int main(){
        employee kow;
        kow.name="kowshik";
        kow.age=21;
        kow.printdel();
        return 0;
     }
