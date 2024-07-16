#include<iostream>
using namespace std;
int main(){
    char grade='C';
    switch (grade){
        case 'A': cout<<"marks are between range 90-100"<<endl;
        break;
        case 'B': cout<<"marks are between range 80-90"<<endl;
        break;
        case 'C': cout<<"marks are between range 70-80"<<endl;
        break;
        case 'D': cout<<"marks are between range 60-70"<<endl;
        break;
        default: cout<<"marks are less than 60"<<endl;
    }
    return 0;
}
