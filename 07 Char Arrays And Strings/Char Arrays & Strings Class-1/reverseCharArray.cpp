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

void reverseCharArray(char arr[], int n){
    int len = getLength(arr,n);
    int i = 0;
    int j = len-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
int main(){
    char arr[1000];
    cin>>arr;
    reverseCharArray(arr,1000);
    cout<<"after reversing: "<<arr<<endl;
    return 0;
}
