#include<iostream>
using namespace std;
//linear search to count number of zero's and one's in an array
void printZeroesAndOnes(int arr[], int n){
    int zeroCount=0;
    int oneCount=0;
    //traverse array
    for(int i=0;i<n;i++){
        int currElement=arr[i];
        if(currElement==0){
            zeroCount++;
        }
        if(currElement==1){
            oneCount++;
        }
    }
    cout<<"total zeroes: "<<zeroCount<<endl;
    cout<<"total ones"<<oneCount<<endl;
}
int main(){
    int arr[10];
    int size;
    cout<<"enter the number of elements: "<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter the input value for index: "<<i<<endl;
        cin>>arr[i];
    }
    printZeroesAndOnes(arr,size);
    return 0;
}
