#include<iostream>
// #include<limits.h> //if any error occurs while using INT_MIN
using namespace std;
//linear search to find max number in array
int findMax(int arr[],int size){
    int maxAns= INT_MIN;
    for(int i=0;i<size;i++){
        maxAns=max(maxAns,arr[i]); //inbuilt max function
        // if(arr[i]>maxAns){
        //     maxAns=arr[i];
        // }
    }
    return maxAns;
}
int main(){
    int arr[100];
    int size;
    cout<<"enter the number of elements: "<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter the input value for index: "<<i<<endl;
        cin>>arr[i];
    }
    cout<<"max number is: "<< findMax(arr,size)<<endl;
    return 0;
}
