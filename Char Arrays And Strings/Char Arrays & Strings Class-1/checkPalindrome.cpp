#include<iostream>
using namespace std;
int getLength(char arr[], int size){
    int count =0;
    int index = 0;
    while(arr[index]!= '\0'){
        //till null character is not found
        count++;
        index++;
    }
    return count;
}

bool checkPalindrome(char arr[], int n){
    int len= getLength(arr,n);
    int i=0;
    int j=len-1;
    while(i<=j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    char arr[1000];
    cin>>arr;
    cout<<"palindrome or not: "<<checkPalindrome(arr,1000)<<endl;
    return 0;
}
