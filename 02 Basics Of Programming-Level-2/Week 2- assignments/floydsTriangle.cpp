#include<iostream>
using namespace std;
//floyd's triangle
/*
1
2 3
4 5 6 
7 8 9 10 
11 12 13 14 15 
16 17 18 19 20 21
22 23 24 25 26 27 28
*/
int main(){
    int n=7;
    int count=1;
    for( int i=0; i<n; i++){
        for(int j=0;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    return 0;
}
