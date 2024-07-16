#include<iostream>
using namespace std;
//sum of AP: 2,4,6,8,10(a: 2, l=10, n=5)
int calculateSumOfAp(int a, int l, int n){
    int ans=((n)*(a+l))/2;
    return ans;
}
int main(){
    int ans= calculateSumOfAp(2,10,5);
    cout<<ans<<endl;
    return 0;
}
