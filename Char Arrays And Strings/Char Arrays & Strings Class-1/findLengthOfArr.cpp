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
int main(){
    //find length of char array
    char arr[1000];
    cin>>arr;
    cout<<getLength(arr,1000)<<endl;

    return 0;
}
