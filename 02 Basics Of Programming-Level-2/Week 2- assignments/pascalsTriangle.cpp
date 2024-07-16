#include<iostream>
using namespace std;
//pascal's triangle
/*
1
1 1 
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
*/
int main(){
    int n=7;
    for( int i=1; i<=n; i++){
        int c=1;
        for(int j=1;j<=i;j++){
            cout<<c<<" ";
            c=c*(i-j)/j;
        }
        cout<<endl;
    }
    return 0;
}
