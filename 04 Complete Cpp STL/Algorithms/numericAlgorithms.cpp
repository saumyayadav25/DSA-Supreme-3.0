#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

int main() {
    vector<int> arr(5);
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;
    
    vector<int> arr2(5);
    arr2[0]=1;
    arr2[1]=2;
    arr2[2]=3;
    arr2[3]=4;
    arr2[4]=5;
    //accumulate
    int totalSum = accumulate(arr.begin(),arr.end(), 0); //initialise with zero
    cout<< totalSum << endl;

    //inner_product
    int innerProd = inner_product(arr.begin(),arr.end(), arr2.begin(), 0);
    cout<< innerProd << endl;

    //partial_sum
    vector<int> result(arr.size());
    partial_sum(arr.begin(), arr.end(), result.begin());
    for(int a:result){
        cout<< a << " ";
    }
    cout<<endl;

    //iota
    vector<int> first(20);
    iota(first.begin(), first.end(), 250);
    for(int a: first){
        cout<< a <<" ";
    }
    return 0;
}
