#include<iostream>
using namespace std;

int main(){
    //nested if
    int age=21;
    bool doYouWantToVote =true;
    if (age>=18){
        cout<<"you can vote"<<endl;
        if(doYouWantToVote == true){
            cout<<"toh fir krde 400 paar"<<endl;
        }
        else{
            cout<<"toh rehndo fir"<<endl;
        }
    }
    else{
        cout<<"you cannot vote"<<endl;
    }
    //ternary
    int money=5;
    // cout<<((money>5)?"very rich":"let's learn coding");
    (money>5)? cout<<"very rich" : cout<<"let's learn coding";
    //switch case
    cout<<"enter your grade"<<endl;
    char grade;
    cin>>grade;
    switch(grade){
        case'A': cout<<"you got >90%"<<endl;
        break;
        case'B': cout<<"you got >80%"<<endl;
        break;
        case'C': cout<<"you got >70%"<<endl;
        break;
        case'D': cout<<"you got >60%"<<endl;
        default : cout<<"failed"<<endl;
    }
    return 0;
}
