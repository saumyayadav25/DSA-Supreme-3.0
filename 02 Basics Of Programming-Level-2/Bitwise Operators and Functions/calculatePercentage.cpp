#include<iostream>
using namespace std;
float calculatePercentage( int sb1, int sb2, int sb3, int sb4, int sb5){
    int sum= sb1+ sb2 + sb3 + sb4 + sb5;
    int totalMarks=500;
    float percentage=(sum*100.0)/totalMarks;
    return percentage;
}
int main(){
    cout<<calculatePercentage(95,95,95,99,88)<<endl;
    return 0;
}
