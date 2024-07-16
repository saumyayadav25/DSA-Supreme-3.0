#include<iostream>
using namespace std;
int getFactorial(int n){
    //base case
    if(n==0||n==1)
        return 1;
    //recursive call
    int recursionAns=getFactorial(n-1);
    int finalAns = n * recursionAns;
    return finalAns;
}

//print counting from N to 1
void printCounting(int n){
    //base case
    if(n==0)
        return;
    //processing
    cout<<n<<" ";
    //recursive call
    printCounting(n-1);
}
//print counting from 1 to N
void printCounting1(int n){
    //base case
    if(n==0)
        return;
    //recursive call
    printCounting1(n-1);
    //processing
    cout<<n<<" ";
}

//power
int pow(int n){
    //base case
    if (n==0)
        return 1;
    //recursive relation
    int recAns=pow(n-1);
    int finalAns=2*recAns;
    return finalAns;
    //processing
}

int fib(int n){
    //base case
    if(n==0||n==1)
        return n;
    //recursive relation
    int ans=fib(n-1)+fib(n-2);
    return ans;
    //processing
}

int getSum(int n){
    //base case
    if(n==1)
        return 1;
    //recursive relation
    int ans=getSum(n-1)+n;
    return ans;
    //processing
}

int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    int fact=getFactorial(n);
    cout<<"Factorial of "<<n<<" is: "<<fact<<endl;
    
    printCounting(5);
    cout<<endl;
    printCounting1(5);
    cout<<endl;

    int power=pow(10);
    cout<<power<<endl;

    int fibonacci=fib(9);
    cout<<fibonacci<<endl;

    cout<<getSum(5);
    return 0;
}