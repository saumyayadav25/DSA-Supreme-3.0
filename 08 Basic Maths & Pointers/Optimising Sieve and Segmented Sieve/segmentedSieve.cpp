#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<bool> Sieve(int n){
    // create a sieve array of N size telling isPrime
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;        
    for(int i=2; i*i<=n;i++){     //optimization 2-> outer loop
        if(sieve[i]==true){
            int j=i*i;            //optimization 1-> inner loop
            while(j<=n){
                sieve[j]=false;
                j += i;
            }
        }
    }
    return sieve;
}
vector<bool>segmentedSieve(int l, int r){
    // make a prime array to mark seg sieve
    vector<bool>sieve=Sieve(sqrt(r));
    vector<int>basePrimes;
    for(int i=0;i<sieve.size();i++){
        if(sieve[i]){
            basePrimes.push_back(i);
        }
    }
    vector<bool>segSieve(r-l+1,true);
    if(l==1 || l==0){
        segSieve[l]=false;
    }
    for(auto prime:basePrimes){
        int first_mul = (l/prime)*prime;
        if(first_mul<l){
            first_mul+=prime;
        }
        int j=max(first_mul,prime*prime);
        while(j<=r){
            segSieve[j-l] = false;
            j+=prime;
        }
    }
    return segSieve;
}

int main(){
    int l=110;
    int r=130;
    vector<bool>ss=segmentedSieve(l,r);
    for(int i=0;i<ss.size();i++){
        if(ss[i]) cout<< i + l << " ";
    }
    return 0;
}