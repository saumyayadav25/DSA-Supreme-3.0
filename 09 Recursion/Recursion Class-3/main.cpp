#include<iostream>
using namespace std;
bool checkSorted(int arr[], int n, int index){
    //base case
    if(index==n-1) return true;   //single elemenet wala array is treated as SORTED array
    //recursive call
    bool currAns = false;
    bool recursionAns = false;
    if(arr[index+1] > arr[index]){
        currAns = true;
    }
    recursionAns = checkSorted(arr,n,index+1);
    return (currAns && recursionAns);
    // if(currAns==true && recursionAns==true) return true;
    // return false;
}

void printSubsequences(string str, int i, string output){
    //base case
    if(i == str.length()) {
        cout << output << endl;
        return;
    }
    //recursive call
    char ch = str[i];
    //include ch
    printSubsequences(str,i+1,output + ch);
    //exclude ch
    printSubsequences(str,i+1,output);
}


int main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    int index=0;
    bool ans = checkSorted(arr,size,index);
    cout<<"Array is sorted or not: "<<ans<<endl;


    string str="abc";
    string output="";
    printSubsequences(str,index,output);


    return 0;
}