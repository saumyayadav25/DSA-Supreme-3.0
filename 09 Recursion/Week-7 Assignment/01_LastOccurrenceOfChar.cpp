#include<iostream>
using namespace std;
void lastOccLToR(string &s, char x,int i, int &ans){
    //base case
    if( i>=s.size()) return;
    //ek case
    if(s[i]==x) ans = i;
    //recursive call
    lastOccLToR(s,x,i+1,ans);
}
void lastOccRToL(string &s, char x,int i, int &ans){
    //base case
    if( i < 0) return;
    //ek case
    if(s[i]==x){
        ans = i;
        return;
    }
    //recursive call
    lastOccRToL(s,x,i-1,ans);
}
int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;
    int ans=-1;
    lastOccLToR(s,x,0,ans);
    cout<<ans<<endl;
    lastOccRToL(s,x,s.size()-1,ans);
    cout<<ans<<endl;
    return 0;
}