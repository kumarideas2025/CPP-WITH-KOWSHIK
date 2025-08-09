#include<iostream>
#include<string>
using namespace std;

    class employee{
       private:
       int spas;

       employee(int sp){
        this->spas=sp;
       }
    };

    int main(){
        employee kow(88);
        cout<<kow.spas;
    }