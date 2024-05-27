#include<iostream>
using namespace std;
//function to find whether given number is even or odd: BITWISE method
bool checkEven( int n){
    if((n&1)==0){ 
        return true ;
    }
    else{
        return false;
    }
}

int main(){
    int n=404;
    int ans = checkEven(n);
    cout<<ans<<endl;
    return 0;
}
