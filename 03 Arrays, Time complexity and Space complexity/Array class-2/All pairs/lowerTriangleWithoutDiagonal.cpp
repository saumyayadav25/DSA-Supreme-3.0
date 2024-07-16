#include<iostream>
using namespace std;
//print all pairs
void printAllPairs(int arr[],int n){
    for(int i=0; i<n;i++){
        //for every i, we are running looping variable "j" from start to end
        //ethod-1
        for(int j=n-1;j>i;j--){ 
            cout<<arr[i]<<", "<<arr[j]<<endl;
        }
        //method-2
        // for(int j=i+1;j<n;j++){
        //     cout<<arr[i]<<", "<<arr[j]<<endl;
        // }
    }
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    printAllPairs(arr,size);
    return 0;
}
