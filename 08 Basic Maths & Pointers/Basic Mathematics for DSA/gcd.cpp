// gfg: GCD of two numbers

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// Euclid Algorithm
class Solution {
    public:
    int gcd(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        while(a>0 && b>0){
            if(a>b) a = a-b;
            else b=b-a;
        }
        return a==0 ? b : a;
    }
};
