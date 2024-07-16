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
    vector<int>v;
    //inserting values
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }
    for(int i=0;i<10;i++){
        v.push_back(80);
    }
    print(v);
    //clear the vector
    v.clear();
    v.push_back(25);
    print(v);
    return 0;
} 
