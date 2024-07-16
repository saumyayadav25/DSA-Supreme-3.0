//week-3 assignment: missing element from an array with duplicates
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,3,5,3,4};
    v.insert(v.begin(),737);
    //737->0... not usefull
    for(int i=1; i<v.size();i++){
        int index=abs(v[i]);
        if(v[index]>0){
            v[index] *= -1;
        }
    }
    for( int i=1; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int missing=-1;
    for(int i=1; i<v.size();i++){
        if(v[i]>0){
            missing=i;
            break;
        }
    }
    cout<<"missing: "<<missing<<endl;
    return 0;
}
