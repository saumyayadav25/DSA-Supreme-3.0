#include<iostream>
using namespace std;

int main(){
    //rectangle pattern
    int length, width;
    cout<<"enter length:"<<endl;
    cin>>length;
    cout<<"enter width"<<endl;
    cin>>width;
    
    //outer loop
    for(int row=0;row<length;row++){
        //innner loop
        for(int col=0;col<width;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
