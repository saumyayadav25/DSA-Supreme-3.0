#include<iostream>
using namespace std;
//linear search for extreme Printing
void extremePrint(int arr[],int n){
    int left=0;
    int right=n-1;
    //method-1
    // while(left<=right){
    //     cout<<arr[left]<<" ";
    //     left++;
    //     if(right>left){
    //         cout<<arr[right]<<" ";
    //     right--;
    //     }
    // }
    
    //method-2
    while(left<=right){
        if(left<=right){
            if(left==right){
                cout<<arr[left]<<" ";
                break;
            }
            else{
                cout<<arr[left]<<" ";
                left++;
                cout<<arr[right]<<" ";
                right--;
            }
        }
    }
}
int main(){
    int arr[]={10,20,30,40,50,60,70};
    int size=7;
    extremePrint(arr,size);
    return 0;
}
