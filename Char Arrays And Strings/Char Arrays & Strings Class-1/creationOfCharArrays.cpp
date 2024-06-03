#include<iostream>
using namespace std;

int main(){
    //creation
    char arr[100];
    cout<<"enter your name: ";
    cin.getline(arr,10);
    //cin>>arr;
    cout<<"your name is " << arr << endl;
    //printing ASCII values of elements  
    cout<<arr[0]<<"->"<<(int)arr[0]<<endl;
    cout<<arr[1]<<"->"<<(int)arr[1]<<endl;
    cout<<arr[2]<<"->"<<(int)arr[2]<<endl;
    cout<<arr[3]<<"->"<<(int)arr[3]<<endl;
    cout<<arr[4]<<"->"<<(int)arr[4]<<endl;
    cout<<arr[40]<<"->"<<(int)arr[40]<<endl;

    //multiple lines input
    char arr1[100];
    cout<<"enter input: ";
    cin.getline(arr1, 80, '\t');
    cout<< endl << arr1 << endl;
    
    return 0;
}
