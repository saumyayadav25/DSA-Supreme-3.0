#include<iostream>
using namespace std;
//function with arrays
void print(int arr[],int size){
    for(int index=0;index<size;index++){
        cout<<arr[index]<<" ";
    }
}
void solve(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=arr[i]*10;
    }
}
int main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    solve(arr,size);
    print(arr,size);
    
    return 0;
}
