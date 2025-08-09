#include<iostream>
#include<string>
using namespace std;

    class employee{
        public:
        string name;
        int age;
        employee(string name,int age){
            this->name=name;
            this->age=age;
        }
        void printdel(){
                    cout<<"the name of your is:"<<this->name<<"salary is"<<this->age<<endl;
        }
    };
    int main(){
        employee kow("kowshik",21);
        kow.printdel();
        return 0;
     }
