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
void convertIntoUpperCase(char arr[], int n){
    int len = getLength(arr,n);
    for(int i=0; i<len; i++){
        char ch = arr[i];
        //if letter if lowercase
        if(ch>='a' && ch<='z'){
            ch= ch-'a'+'A';
        }
        
        arr[i]=ch;
    }
}
void convertIntoLowerCase(char arr[], int n){
    int len = getLength(arr,n);
    for(int i=0; i<len; i++){
        char ch = arr[i];
        //if letter if uppercase
        if(ch>='A' && ch<='Z'){
            ch= ch-'A' + 'a';
        }
        
        arr[i]=ch;
    }
}
int main(){
    char arr[1000];
    cin>>arr;
    convertIntoUpperCase(arr,1000);
    cout<<arr<<endl;
    convertIntoLowerCase(arr,1000);
    cout<<arr<<endl;
    return 0;
}
