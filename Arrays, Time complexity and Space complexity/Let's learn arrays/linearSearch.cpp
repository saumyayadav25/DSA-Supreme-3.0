#include<iostream>
using namespace std;
//linear search
bool findTarget(int arr[],int size,int target){
    //traverse the entire array
    for(int i=0;i<size;i++){
        int currentElement=arr[i];
        if(currentElement==target){
            //found
            return true;
        }
    }
    //reached here: target not found in the array
    return false;
}
int main(){
    // int arr[]={10,20,30,40,50};
    // int size=5;
    int target=40;
    int arr[100];
    int size;
    cout<<"enter the number of elements: "<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter the input value for index: "<<i<<endl;
        cin>>arr[i];
    }
    bool ans=findTarget(arr,size,target);
    cout<<"ans: "<<ans<<endl;
    return 0;
}
