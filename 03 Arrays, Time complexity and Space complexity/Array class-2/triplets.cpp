#include<iostream>
using namespace std;
//print all triplets
void printAllTriplets(int arr[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<< arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
                count++;
            }
        }
    }
    cout<<"total triplets printed: "<< count<<endl;
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    printAllTriplets(arr,size);
    return 0;
} 
