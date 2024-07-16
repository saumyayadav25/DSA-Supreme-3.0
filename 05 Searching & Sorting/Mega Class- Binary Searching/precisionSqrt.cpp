#include<iostream>
using namespace std;
//sqrt with precision
int mySqrt(int n){
    //O(logn)
    int s = 0, e=n;
    int ans=0;
    while(s<=e){
        int mid= (s + e) >> 1;
        if(mid*mid <= n){
            ans = mid;
            s=mid+1; 
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

double myPrecisionSqrt(int n){
    double sqrt = mySqrt(n); 
    int precision = 12;
    double step = 0.1;
    //O(precision)
    while(precision--){
        double j = sqrt; //j->/7.0
        while(j*j<=n){
            //store and compute
            sqrt = j;
            j+=step; //j->7.1
        }
        //after this while loop i got 1 precisiom ans
        step/=10;
    }
    return sqrt;
}
int main(){
    //TC: O(logn) + O(precision)
    int n = 63;
    double ans = myPrecisionSqrt(n);
    //cout<<ans<<endl; //cout prints only upto 5 precision
    //to print precision more than 5:
    printf("Precision sqrt:  %.12f\n", ans);
    return 0;
}
