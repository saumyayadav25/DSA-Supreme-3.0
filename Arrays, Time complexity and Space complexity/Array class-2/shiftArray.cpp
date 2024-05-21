#include<iostream>
using namespace std;
//shift an array
void rotateArray(int arr[], int size, int n){
    //size: size of array
    //n: number of elements by which we have to shift
    n=n%size;
    
    if(n==0){
        //no need to do anything
        return;
    }
    //step-1: copy last n elements into a temp array
    int temp[1000];
    int index=0;
    for(int i=size-n;i<size;i++){
        temp[index]=arr[i];
        index++;
    }
    //step-2: shift array elements by n places
    for(int i=size-1;i>=0;i--){
        if(i-n>=0){
            arr[i]=arr[i-n];
        }
    }
    //step-3: copy temp elements into original array' starting
    for( int i=0; i<n;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int arr[]={10,20,30,40,50,60};
    int size=6;
    //cyclically rotate array by 2 places
    int n = 2;
    //print original array
    cout<<"Array before rotating: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rotateArray(arr,size,n);
    //print array after rotation
    cout<<"Array after rotating : "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
} 
