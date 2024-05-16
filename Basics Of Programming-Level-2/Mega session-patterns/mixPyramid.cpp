#include<iostream>
using namespace std;
//pattern
//**** ****
//***   ***
//**     **
//*       *
//*       *
//**     **
//***   ***
//**** ****

void mixPyramid(int n){
    //upper half
    for(int i=0;i<n;i++){
        //1st part: stars
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        //2nd part: spaces
        for(int j=0;j<2*i+1;j++){
            cout<<" ";
        }
        //3rd part: stars
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //lower half
    for(int i=0;i<n;i++){
        //1st part: stars
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        //2nd part: spaces
        for(int j=0;j<2*(n-i)-1;j++){
            cout<<" ";
        }
        //3rd part: stars
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}
int main(){
    int n;
    cin>>n;
    mixPyramid(n);
    return 0;
}
