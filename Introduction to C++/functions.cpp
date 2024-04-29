#include<iostream>
#include<cmath>
using namespace std;

void printCounting(){
    for(int i=1;i<=5;i++){
        cout<<i<<" ";
    } cout<<endl;
}

int sum(int a,int b){
    int totalSum=a+b;
    return totalSum;
}

void printMyName();
int getMultiplication(int x,int y, int z){
    int result=x*y*z;
    return result;
}

char convertIntoUpperCase(char ch){
    char answer= ch-'a'+'A';
    return answer;
}

int main(){
    printCounting();

    printMyName();
    
    int ans=sum(5,500);
    cout<<ans<<endl;

    char character='z';
    char upCase= convertIntoUpperCase(character);
    cout<<upCase<<endl;

    //function call
    int mul=getMultiplication(9,5,7);
    cout<<mul<<endl;
    
    return 0;
}

void printMyName(){
    cout<<"Saumya"<<endl;
}
