#include<iostream>
using namespace std;
//sqrt (binary search with precision)
double BSPrecision(int n){
    double start = 0;
    double end= n;
    double ans = 0;
    while((end-start) >= 0.000000001){
        double mid= (start + end )/2;
        double sq= mid*mid;
        if(sq<= n){
            ans = mid;
            start = mid;
        }
        else{
            end = mid;
        }
    }
    return ans;
}
int main(){
    int n = 63;
    double ans = BSPrecision(n);
    printf("Precision sqrt:  %.9f\n", ans);
    return 0;
}
