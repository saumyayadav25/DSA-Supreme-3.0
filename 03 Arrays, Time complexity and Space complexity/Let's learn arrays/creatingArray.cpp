#include<iostream>
using namespace std;
int main(){
    //creation
    int arr[10];
    //error if you don't define arr size
    //int brr[];
    //initialize
    int crr[]={10,20,40,90};
    int drr[4]={5};
    //indexing
    cout<<drr[0]<<endl;
    cout<<drr[1]<<endl;
    cout<<crr[0]<<endl;
    cout<<crr[1]<<endl;
    //accessing out of index value in array
    cout<<crr[4]<<endl; //may give exception or give garbage value
    //fill
    fill(arr,arr+10,23);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[9]<<endl;
    //taking input in arrays: use loop 
    int arr1[5];
    for(int i=0; i<5;i++){
        cout<<"enter the value for index "<<i<<": ";
        cin>>arr1[i];
    }
    //output
    for(int index=0;index<5;index++){
        cout<<arr1[index]<<" ";
    }
    return 0;
}
