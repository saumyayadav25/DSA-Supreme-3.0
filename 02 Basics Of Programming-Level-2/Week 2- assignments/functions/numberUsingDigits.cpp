#include<iostream>
using namespace std;
//create number using digits
int createNumberUsingDigits(int numberOfDigits){
    int num=0;
    for(int i=0; i<numberOfDigits;i++){
        cout<<"enter digit: "<<endl;
        int digit;
        cin>>digit;
        num = num*10 + digit;
        cout<<"number created so far :" << num << endl;
    }
    return num;
}
int main(){
    int numberOfDigits;
    cin >> numberOfDigits;
    int num = createNumberUsingDigits(numberOfDigits);
    cout<<"number created using digits : "<< num<<endl;
    return 0;
}
