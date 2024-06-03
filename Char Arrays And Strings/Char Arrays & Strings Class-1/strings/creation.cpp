#include<iostream>
using namespace std;
int main(){
    //creation
    string str;
    cout<<"enter the input: "<<endl;
    // cin>>str;
    // cout<<"str: "<<str<<endl;
    // cout<<str[0]<<endl;
    str.push_back('s');
    str.push_back('a');
    str.push_back('u');
    str.push_back('m');
    str.push_back('y');
    str.push_back('a');
    str.pop_back();
    cout<<str<<endl;

    string sentence;
    //cin>>sentence;
    getline(cin, sentence,'\n');
    cout<<sentence<<endl;
    return 0;
}
