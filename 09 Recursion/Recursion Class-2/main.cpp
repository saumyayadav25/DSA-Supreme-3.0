#include<iostream>
#include<vector>
using namespace std;
void printArray(int arr[], int size, int index){
    //base case
    if(index==size) return;
    //recursive relation
    cout<<arr[index]<<" ";
    printArray(arr,size, index+1);
}

bool searchInArray(int arr[], int size, int index, int target){
    //base case 
    if(index==size) return false;
    if(arr[index]==target) return true;
    //recursive relation
    bool ans = searchInArray(arr, size, index+1, target);
    return ans;
}

void maxInArray(int arr[], int size,int index, int &maxi){
    //base case
    if(index==size) return;
    //recursive relation
    maxi = max(maxi,arr[index]);
    maxInArray(arr,size,index+1, maxi);
}

void minInArray(int arr[], int size,int index, int &mini){
    //base case
    if(index==size) return;
    //recursive relation
    mini = min(mini,arr[index]);
    minInArray(arr,size,index+1, mini);
}

void printAllOdds(int arr[], int n, int index){
    //base case
    if(index==n) return;
    //recursive relation
    if((arr[index])&1) cout<<arr[index]<<" ";
    printAllOdds(arr,n,index+1);
}

void printAllEvens(int arr[], int n, int index){
    //base case
    if(index==n) return;
    //recursive relation
    if((arr[index])%2==0) cout<<arr[index]<<" ";
    printAllEvens(arr,n,index+1);
}

void printDigits(int n){
    //base case
    if(n==0) return;
    //recursive relation
    int newNumber=n/10;
    printDigits(newNumber);
    int digit=n%10;
    cout<<digit<<" ";
}

int main(){
    int arr[]={10,11,12,13,14,15};
    int size = 6;
    int index = 0;
    printArray(arr, size, index);
    cout<<endl;

    int target=50;
    cout<<searchInArray(arr,size,index,target)<<endl;

    int maxi=INT_MIN;
    maxInArray(arr,size,index,maxi);
    cout<<"Max no.: "<< maxi<<endl;

    int mini=INT_MAX;
    minInArray(arr,size,index,mini);
    cout<<"Min no.: "<< mini<<endl;

    printAllOdds(arr,size,index);
    cout<<endl;

    printAllEvens(arr,size,index);
    cout<<endl;

    int n=21478;
    printDigits(n);
    return 0;
} 
