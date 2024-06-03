#include<iostream>
using namespace std;

int main(){
    char arr1[100];
    cout<<"enter the input: "<<endl;
    cin>>arr1;
    char arr2[100];
    cout<<"enter the input: "<<endl;
    cin>>arr2;
    cout<<strcat(arr1,arr2)<<endl;
    cout<<strlen(arr1)<<endl;
    return 0;
}
