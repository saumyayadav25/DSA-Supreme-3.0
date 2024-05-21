#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>v){
    int size=v.size();
    cout<<"printing vector: "<<endl;
    for(int i=0; i<size;i++){
        // cout<<v[i]<< " ";
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}
int main(){
    
    //how to copy vector
    vector<int>arr={1,2,3,4,5};
    vector<int>arr1(arr);
    arr1.pop_back();
    arr.push_back(50);
    print(arr1);
    
    print(arr);
    return 0;
} 
