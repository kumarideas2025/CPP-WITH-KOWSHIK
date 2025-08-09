#include<iostream>
using namespace std;
int main(){
    int arr[2][3]={{2,3,4},{5,9,8}};
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<"value is"<<i<<","<<j<<"is"<<arr[i][j]<<endl;
        }
    }
}