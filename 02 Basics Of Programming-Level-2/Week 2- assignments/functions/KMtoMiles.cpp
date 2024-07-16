#include<iostream>
using namespace std;
//KM to Miles
float KMtoMiles(float km){
    float _1kmMile= 0.621371;
    float miles = km * _1kmMile;
    return miles;
}
int main(){
    float km;
    cout<<"enter value in km: ";
    cin>>km;
    float miles=KMtoMiles(km);
    cout<<"value in miles: "<<miles<<endl;
    return 0;
}
