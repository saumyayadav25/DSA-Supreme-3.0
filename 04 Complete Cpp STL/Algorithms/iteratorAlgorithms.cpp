#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printDouble(int a){
    cout<< 2*a <<" ";
}
bool checkEven(int a){
    return a%2==0;
}
int main() {
    vector<int> arr(6);
    arr[0]=11;
    arr[1]=11;
    arr[2]=21;
    arr[3]=40;
    arr[4]=50;
    arr[5]=60;
    //unique
    auto it= unique(arr.begin(), arr.end()); //returns iterator
    //before it: unique elements
    //after it: duplicate elements
    arr.erase(it, arr.end());
    for(int a:arr){
        cout<<a<<" ";
    }
    cout<<endl;

    //rotate
    rotate(arr.begin(),arr.begin()+3, arr.end());
    for(int a:arr){
        cout<<a<<" ";
    }
    cout<<endl;

    //for_each
    for_each(arr.begin(),arr.end(),printDouble);
    cout<<endl;

    //find
    int target=40;
    auto it1 = find(arr.begin() , arr.end() , target); //returns iterator
    cout<< *it1 <<endl;
    
    //find_if
    find_if(arr.begin(), arr.end(), checkEven);
    cout<< *it1 <<endl;
    
    //count
    int targetc=11;
    int ans=count(arr.begin(), arr.end(), targetc);
    cout<<ans<<endl;
    
    //count_if
    int ans2= count_if(arr.begin(), arr.end(), checkEven);
    cout<<ans2<<endl;

    //sort
    sort(arr.begin(), arr.end());
    for(int a:arr){
        cout<<a<<" ";
    }
    cout<<endl;

    //reverse
    reverse(arr.begin(), arr.end());
    for(int a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
    
    //partition
    auto it2 = partition(arr.begin(),arr.end(), checkEven);
    //even values are at left side of partition
    for(int a: arr){
        cout<< a << " ";
    }
    return 0;
}
