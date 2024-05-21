#include<iostream>
#include<vector>
using namespace std;
void print(vector<char>v){
    int size=v.size();
    cout<<"printing vector: "<<endl;
    for(int i=0; i<size;i++){
        cout<<v[i]<< " ";
        
    }
    cout<<endl;
}
void print2(vector<int>v){
    cout<<"printing vector using method-2"<<endl;
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    print2(v1);
    vector<char>v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    v.push_back('d');
    // cout<<"Front element: "<<v[0]<<endl;
    cout<<"Front element: "<<v.front()<<endl;
    // cout<<"End element: "<<v[v.size()-1] <<endl;
    cout<<"End element: "<<v.back() <<endl;
    return 0;
} 
