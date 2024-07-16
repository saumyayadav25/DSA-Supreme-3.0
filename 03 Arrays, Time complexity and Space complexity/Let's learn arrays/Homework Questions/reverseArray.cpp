#include<iostream>
using namespace std;
//reverse an array
void reverseArray(int arr[],int n){
    int l=0, h=n-1;
    while(l<h){
        // swap(arr[l],arr[h]);
        // l++;
        // h--;
        swap(arr[l++],arr[h--]);
    }
}
int main(){
    int arr[]={10,20,30,40,50,60,70,80};
    int n=8;
    //concept:
    //initialize value l=0;h=n-1
    //swap arr[l] and arr[h]

    //method-1: custom approach
    
    // reverseArray(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
    
    //method-2
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
